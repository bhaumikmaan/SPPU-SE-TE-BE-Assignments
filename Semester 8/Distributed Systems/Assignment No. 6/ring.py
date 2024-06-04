class Ring:
   def __init__(self, num_process=5):
       self.num_process = num_process
       self.coordinator = 5
       self.active_processes = set(range(1, num_process + 1))

   def election(self, process_id):
       if self.coordinator is None:
           # Only one process in the system
           self.coordinator = process_id
           print(f"Process {process_id} is the coordinator.")
           return

       if process_id not in self.active_processes:
           print(f"Process {process_id} is not active.")
           return

       highest_id = process_id
       next_process = (process_id % self.num_process) + 1

       while next_process != process_id:
           if next_process in self.active_processes:
               print(
                   f"Process {process_id} is passing election message to process {next_process}."
               )
               if next_process > highest_id:
                   highest_id = next_process
           else:
               print(
                   f"Process {next_process} is down and cannot receive the election message."
               )
           next_process = (next_process % self.num_process) + 1

       self.coordinator = highest_id
       print(f"Process {self.coordinator} is the coordinator.")

   def start_election(self, process_id):
       if process_id not in self.active_processes:
           print(f"Process {process_id} is not active.")
           return

       print(f"Process {process_id} starts the election process.")
       self.election(process_id)

   def bring_up_process(self, process_id):
       if process_id in self.active_processes:
           print(f"Process {process_id} is already up.")
           return

       self.active_processes.add(process_id)
       print(f"Process {process_id} is up.")

   def bring_down_process(self, process_id):
       if process_id not in self.active_processes:
           print(f"Process {process_id} is already down.")
           return

       self.active_processes.remove(process_id)
       print(f"Process {process_id} is now down.")

       if self.coordinator == process_id:
           self.start_election(process_id)

   def print_active_processes(self):
       print("Active processes:")
       for process_id in self.active_processes:
           print(f"Process {process_id}")

   def print_coordinator(self):
       if self.coordinator is None:
           print("Coordinator: None")
       else:
           print(f"Coordinator: Process {self.coordinator}")


if __name__ == "__main__":
   ring = Ring()

   while True:
       print("-------------------------------------")
       print("1) Start Election")
       print("2) Bring Up Process")
       print("3) Bring Down Process")
       print("4) Print Active Processes")
       print("5) Print Coordinator")
       print("6) Exit")

       choice = int(input("Enter choice: "))

       if choice == 1:
           process_id = int(input("Enter process id to start the election: "))
           ring.start_election(process_id)

       elif choice == 2:
           process_id = int(input("Enter process id to bring up: "))
           ring.bring_up_process(process_id)

       elif choice == 3:
           process_id = int(input("Enter process id to bring down: "))
           ring.bring_down_process(process_id)

       elif choice == 4:
           ring.print_active_processes()

       elif choice == 5:
           ring.print_coordinator()

       else:
           break
