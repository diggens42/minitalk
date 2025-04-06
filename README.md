
# minitalk

`minitalk` is a simple communication program that implements a client-server model using UNIX signals to exchange messages. The server listens for incoming signals and prints the received string, while the client sends a string to the server using a given server's PID.

## Features

- The server must be launched first, and it will print its Process ID (PID) to the terminal.
- The client requires two parameters:
  - The server’s PID.
  - The string to send to the server.
- Once the server receives the string, it prints the message to the terminal.
- The server is designed to handle consecutive strings from multiple clients without needing to restart.
- The communication between the client and server relies on UNIX signals, specifically `SIGUSR1` and `SIGUSR2`.

## How it works

1. **Server**: The server listens for signals and processes them. Upon startup, it prints its PID, which the client will use for communication.
2. **Client**: The client sends a string to the server by passing the server's PID and the message as arguments. The message is transmitted bit by bit using `SIGUSR1` and `SIGUSR2`.
3. **Signal Handling**: The server decodes the incoming signals to reconstruct the string and then displays it.

## Requirements

- The server must be able to handle multiple client requests in a row without restarting.
- The program must be efficient, as processing delays will be noticed if displaying 100 characters takes more than one second.

## Usage

1. **Start the Server**:
   ```bash
   ./server
   ```

2. **Start the Client**:
   ```bash
   ./client <server_pid> <message>
   ```

## Example

- First, start the server:
   ```bash
   ./server
   ```

   The server will print its PID (e.g., `12345`).

- Then, in another terminal, run the client:
   ```bash
   ./client 12345 "Hello, server!"
   ```

   The server will display the received message: `Hello, server!`
