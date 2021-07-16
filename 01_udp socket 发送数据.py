import socket

def main():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # 绑定 ip & port
    localaddr = ("", 7788) # 空表示本机 ip
    udp_socket.bind(localaddr)
    # 发送数据
    udp_socket.sendto(b"hallo", ('192.168.3.5', 8081))
    udp_socket.close()

if __name__ == "__main__":
    main()