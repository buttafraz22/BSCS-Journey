# -*- coding: utf-8 -*-
"""
Created on Sat Oct  1 09:46:06 2022

@author: HP
"""

import requests
import pandas as pd
from bs4 import BeautifulSoup

# import urllib.request
START = 1
END = 10
all_data = []
def get_words_in_page(url):
    soup = BeautifulSoup(requests.get(url).content, "html.parser")
    
    for ul in soup.select("div.e181zu8w1"):
            car_name = ul.find_previous("h6").get_text(strip=True)
            # print(car_name)
            info = [li.get_text(strip=True) for li in ul.select("div.e1me6z3j2")]
            # print(info)
            all_data.append([car_name, *info])


base_url = "https://carvago.com/cars?sort=recommended&page=1&limit=20"

for paging in range(START,END):
    if paging < 2:    
        print(base_url)
        get_words_in_page( base_url ) 
        base_url = "https://carvago.com/cars?sort=recommended&page="
        print(paging)          
    if paging >= 2:    
        url = base_url+str(paging )+ "&limit=20"
        print(url)
        print(type(url))
        get_words_in_page( url )
        
try:
    df = pd.DataFrame(all_data, columns=["Car Name", "Year", "KM", "Type", "CC", "Type 2" , "GRADE"])
    print(df)
    df.to_csv("data.csv", index=False)
except:
    df = pd.DataFrame(all_data, columns=["Car Name", "Year", "KM", "Type", "CC", "Type 2"])
    df.to_csv("data.csv", index=False)



