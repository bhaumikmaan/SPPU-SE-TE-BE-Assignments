class Bully:
   def __init__(self, num_process=5):
       # Initialize the Bully object with the number of processes and their states
       self.num_process = num_process
       self.state = [True for _ in range(num_process)]
       self.leader = num_process

   def election(self, process_id):
       # Perform the election algorithm to elect a coordinator
       print(f"Process {process_id} is sending election messages to higher processes")
       cod = process_id
       for i in range(process_id + 1, self.num_process + 1):
           if self.state[i - 1]:
               print(
                   f"Process {process_id} is sending election message to process {i}"
               )
               cod = i

       print(f"Process {cod} is sending coordinator message to all")

       # Update the leader to the elected coordinator
       self.leader = cod
       print(f"Process {self.leader} is now coordinator.")

   def up(self, process_id):
       # Bring up a process and trigger an election if necessary
       if self.state[process_id - 1]:
           print(f"Process {process_id} is already up")
           return
       else:
           self.state[process_id - 1] = True
           print(f"Process {process_id} is up")
           self.election(process_id)

   def down(self, process_id):
       # Bring down a process and initiate a new election if the leader is down
       if not self.state[process_id - 1]:
           print(f"Process {process_id} is already down.")
       else:
           self.state[process_id - 1] = False
           print(f"Process {process_id} is now down")

           if self.leader == process_id:
               # If the leader is down, randomly select a new active process and trigger an election
               active = [i for i, _ in enumerate(self.state) if i]
               import random

               index = random.randint(0, len(active) - 1)
               self.election(active[index])

   def message(self, process_id):
       # Send a message and check if the coordinator is active
       if self.state[process_id - 1]:
           if self.state[self.leader - 1]:
               print("OK")
           else:
               # If the coordinator is down, initiate a new election
               self.election(process_id)
       else:
           print(f"Process {process_id} is down.")


if __name__ == "__main__":
   # Create a Bully object
   bully = Bully()

   print("5 Active processes are:")
   print("Processes up = p1 p2 p3 p4 p5")
   print(f"Process {bully.leader} is the coordinator")

   choice = 5

   while choice != 4:
       print("-------------------------------------")
       print("1) Up a process")
       print("2) Down a Process")
       print("3) Send a Message")
       print("4) Exit")

       choice = int(input("Enter choice: "))

       if choice == 1:
           process_id = int(input("Enter process id: "))
           bully.up(process_id)

       elif choice == 2:
           process_id = int(input("Enter process id: "))
           bully.down(process_id)

       elif choice == 3:
           process_id = int(input("Enter process id: "))
           bully.message(process_id)

       else:
           break
