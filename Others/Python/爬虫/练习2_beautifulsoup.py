from bs4 import BeautifulSoup
import requests
url = 'http://www.icourse163.org/learn/BIT-1001870001?tid=1003245012#/learn/content?type=detail&id=1004574444&cid=1005754029&replay=true'
data = requests.get(url)
soup = BeautifulSoup(data.text, 'html.parser')
print(soup)