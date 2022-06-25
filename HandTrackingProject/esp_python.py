import urllib.request
import http

base = "http://<ip address of NodeMCU>/"


def transfer(my_url):  # use to send and receive data
    try:
        n = urllib.request.urlopen(base + my_url).read()
        n = n.decode("utf-8")
        return n

    except http.client.HTTPException as e:
        return e


# you can send pwm255 and then decode it to get pwm or more variables
