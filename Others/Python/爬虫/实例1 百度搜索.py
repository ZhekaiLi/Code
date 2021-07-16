import requests
try:
	keyword = 'python'
	wd = {'wd': keyword}
	ua = {'User-Agenr':'Mozilla/5.0'}
	r = requests.get('https://www.icourse163.org/', params=wd, headers=ua)
	r.raise_for_status() #如果状态不是200，引发HTTPError异常
	r.encoding = r.apparent_encoding
	print(r.text)
except:
	print("产生异常")
