# -*- coding: utf-8 -*-
"""
Created on Sun Nov 25 12:30:28 2018

@author: lzk12
"""
import urllib
url = 'https://wenku.baidu.com/view/81a70c0e26fff705cd170a61.html'

rsp = urllib.request.urlopen(url)
import chardet
html = rsp.read()
cs = chardet.detect(html) 
	#生成字典cs，储存html的相关属性 {'encoding': …, 'confidence': …, 'language': …}，其中'encoding'  对应解码方式
html = html.decode(cs.get('encoding', 'utf-8'))
print(html)