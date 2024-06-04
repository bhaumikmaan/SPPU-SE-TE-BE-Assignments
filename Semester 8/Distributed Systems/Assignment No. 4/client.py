import socket
import time
import json
import random

SERVER_IP = "127.0.0.1"
PORT = 5000


def get_local_time():
   return random.randint(int(time.time() - 1e5), int(time.time() + 1e5))


def main():
   ## Connect to server
   client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   client_socket.connect((SERVER_IP, PORT))
   print(f"Connected to {SERVER_IP}:{PORT}")

   ## Get local time
   client_local_time = get_local_time()

   time_adjusted = False

   while not time_adjusted:
       server_res = json.loads(client_socket.recv(1024).decode())

       if server_res["operation"] == "time_req":
           ## Send local time to server
           print(f"Local time: {client_local_time}")
           client_socket.send(json.dumps({"client_time": client_local_time}).encode())

       if server_res["operation"] == "time_adj":
           ## Adjust local time
           print(f"Time adjustment: {server_res['adjusted_time']}")
           client_local_time += float(server_res["adjusted_time"])

           print(f"Adjusted time: {client_local_time}")

           time_adjusted = True

   client_socket.close()


if __name__ == "__main__":
   main()
