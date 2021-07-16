import requests
import os
root = 'D://pics//'
url = 'https://images0.cnblogs.com/blog/708383/201502/011928272847003.png'
path = root + url.split('/')[-1] #获取源图片名
try:
    if not os.path.exists(root):
        os.mkdir(root)
    if not os.path.exists(path):
        r = requests.get(url)
        r.raise_for_status() #如果状态不是200，引发HTTPError异常
        with open(path, 'wb') as f:
            f.write(r.content)
            f.close()
        print('sucess')
    else:
	    print('no file')
except:
	print("wrong")
