import socket

def send_msg(udp_socket):
    dest_ip = input("对方的 ip：")
    dest_port = int(input("对方的 port："))
    send_data = input("需要发送的内容：")
    udp_socket.sendto(send_data.encode("utf-8"), (dest_ip, dest_port))

def recv_msg(udp_socket):
    recv_data = udp_socket.recvfrom(1024) # 1024 表示本次接收的最大字节数
    print("%s:%s" % (str(recv_data[1]), recv_data[0].decode("gbk")))

def main():
    # 创建 socket
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # 绑定信息
    udp_socket.bind("", 7788)

    while True:
        print("----聊天器----")
        print("1:发消息")
        print("2:收消息")
        print("0:退出")
        op = input("请输入功能：")

        if op == "1":
            # 发送
            send_msg(udp_socket)
        elif op == "2":
            # 接收并显示
            recv_msg(udp_socket)
        elif op == "0":
            break
        else:
            print("输入错误，请重新输入")

if __name__ == "__main__":
    main()