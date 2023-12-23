import asyncio
import struct

# Constants for UAP message fields
MAGIC_NUMBER = 50273  # 0xC461 as an unsigned 16-bit integer
VERSION = 1

# Define message types
HELLO = 0
DATA = 1
ALIVE = 2
GOODBYE = 3

class Client:
    def __init__(self):
        self.transport = None
        self.session_id = None
        self.sequence_number = 0

    def send_uap_message(self, command, data=None):
        header = struct.pack('!HHBBi', MAGIC_NUMBER, VERSION, command, self.sequence_number, self.session_id)
        if data:
            message = header + data
        else:
            message = header
        self.transport.sendto(message, ('localhost', 8888))

    async def start(self):
        self.transport, _ = await asyncio.get_event_loop().create_datagram_endpoint(
            lambda: ClientProtocol(self),
            remote_addr=('localhost', 8888),
        )

    def close(self):
        if self.transport:
            self.send_uap_message(GOODBYE)
            self.transport.close()

class ClientProtocol:
    def __init__(self, client):
        self.client = client

    def connection_made(self, transport):
        self.client.transport = transport

    def datagram_received(self, data, addr):
        header = struct.unpack('!HHBBi', data[:12])
        _, _, command, seq_num, _ = header

        if command == ALIVE:
            self.client.sequence_number += 1

    def connection_lost(self, exc):
        print("Connection closed.")
        asyncio.get_event_loop().stop()

async def main():
    client = Client()
    await client.start()

    try:
        while True:
            user_input = input("Enter a message (or 'q' to quit): ")
            if user_input == 'q':
                client.close()
                break
            client.send_uap_message(DATA, user_input.encode())
            await asyncio.sleep(0.1)  # Add a small delay to allow processing

    except EOFError:
        client.close()

if __name__ == '__main__':
    asyncio.run(main())

