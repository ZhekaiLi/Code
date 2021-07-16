# -*- coding: utf-8 -*-
"""
Created on Tue Dec 18 16:02:50 2018

@author: lzk12
"""
import requests
def getHTMLTEXT(url):
    try:
        ua = {'User-Agent':'Mozilla/5.0'}
        r = requests.get(url, timeout=30, headers=ua)
        r.raise_for_status() #如果状态不是200，引发HTTPError异常
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "产生异常"

if __name__ == "__main__":
    url = "https://www.amazon.cn/dp/B07746N2J9?_encoding=UTF8&pf_rd_i=desktop&pf_rd_m=A1AJ19PSB66TGU&pf_rd_p=904c8971-1a72-44a1-80f7-42d98a666333&pf_rd_r=4JGQSVNHXP6RJRCV5ZDR&pf_rd_s=Tcg-slide-1&pf_rd_t=36701&ref_=p-Tcg-slide-1--19a7c3bd-732a-4869-be69-9b9f15ac8949"
    print(getHTMLTEXT(url))
        

