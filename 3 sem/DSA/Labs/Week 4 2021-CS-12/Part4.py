# -*- coding: utf-8 -*-
"""
Created on Sat Oct  1 22:37:09 2022

@author: Afraz Butt
"""
import requests as rq
from bs4 import BeautifulSoup
import pandas as pd

course_title = []
descriptions = []
instructors = []
semesters = []
#inner_text = []
course_code = []

r = rq.get('http://eduko.spikotech.com/Course/Index')
html_content = r.content

# print(html_content)

soup = BeautifulSoup(html_content,'html.parser')
# print(soup.prettify)

for item in soup.find_all('a',attrs={'class':'min-vh-100 d-flex flex-column justify-content-between'}):
    inner_text = []
    title = item.find('h4',attrs = {'class':'card-title'}) #BeautifulSoup 3 Docs
    
    for tag in item.find_all('h7')[0:]:
        text = tag.text.strip()
        inner_text.append(text)
    
    istructor = inner_text[0]
    semester = inner_text[1]
    # print(istructor)
    
    description = item.find('p',id = 'CourseDescription') #Just saw Bs4 docs ... xD
    courseCode = item.find('div',id='CourseCode')
    
    course_title.append(title)
    descriptions.append(description)
    instructors.append(istructor)
    semesters.append(semester)
    course_code.append(courseCode)

# print(course_title)

df = pd.DataFrame({'Title':course_title , 'Instructors' : instructors , 'Semester' : semesters, 'Description':descriptions
                   , 'Course Code':course_code})

df.to_csv('Csv/data_p4.csv',index=False,encoding='utf-8')