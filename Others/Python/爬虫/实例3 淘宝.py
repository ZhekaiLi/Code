import requests
import re

def getHTMLText(url):
	try:
		r = requests.get(url, timeout=30)
		r.raise_for_status() #如果状态不是200，引发HTTPError异常
		r.encoding = r.apparent_encoding
		return r.text
	except:
		print('')

def parsePage(ilt, html): #利用正则表达式
	try:
		plt = re.findall(r'\"view_price\"\:\"[\d\.]*\"', html)
		tlt = re.findall(r'\"raw_price\"\:\".*?\"', html)
		for i in range(len(plt)):
			price = eval(plt[i].split(':')[1])
			titel = eval(tlt[i].split(':')[1])
			ilt.append([price, title])
	except:
		print('')

def printGoodList(ilt):
	tplt = '{:4}\t{:8}\t{:16}'
	print(tplt.format('序号', '价格', '商品名称'))
	count = 0
	for g in ilt:
		count += 1
		print(tplt.format(count, g[0], g[1]))

def main():
	goods = '男装'
	depth = 10
	start_url = 'https://s.taobao.com/search?q=' + goods
	infoList = []
	for i in range(depth):
		try:
			url = start_url + '&s=' + str(44*i)
			html = getHTMLText(url)
			parsePage(infoList, html)
		except:
			continue
	printGoodList(infoList)

main()