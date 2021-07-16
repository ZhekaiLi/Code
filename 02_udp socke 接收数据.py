import socket

def main():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # 绑定 ip & port
    localaddr = ("", 7788) # 空表示本机 ip
    udp_socket.bind(localaddr)
    # 接收数据
    recv_data = udp_socket.recvfrom(1024) # 1024 表示本次接收的最大字节数
    print(recv_data)
    udp_socket.close()

if __name__ == "__main__":
    main()