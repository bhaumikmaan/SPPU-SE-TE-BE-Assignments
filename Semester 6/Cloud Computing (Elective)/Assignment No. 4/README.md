## Transer .txt file from one VM to another

Let VM1 and VM2 be two virtual machines where we are sending the file from VM1 to VM2

* In VM1 enter, touch filename.txt
* In VM1 enter, nano filename.txt & make write some text into it
* In VM2 enter, ifconfig and keep the IP address safe to enter in VM1
* If not configured, configure the NAT settings in VM2 to get the translated IP address for file transfer
* In VM1 enter, scp filename <username>@<ip>:/<address> (replace <> with relevant values)
* Finally check in VM2 whether or not file has been transfered by using cat filename.txt
