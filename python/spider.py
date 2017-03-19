import urllib
import urllib2
url='http://114.215.17.136/'          #统一资源定位
values={'search':'hunter'}          #请求变量
header={'User-Agent':'user_agent'}  #更改头标，模拟浏览器
date=urllib.urlencode(values)       #编码请求数据
request=urllib2.Request(url,date,header)        #映射请求
#################################   #检查是否成功获取URL
try:
    urllib2.urlopen(request,timeout=5)
except urllib2.HTTPError,e:     #HTTPError是URLError的子集
    print 'HTTP Error:',e.code
except urllib2.URLError,e:
    print 'URL Error:',e.reason
#################################
else:
    response=urllib2.urlopen(request,timeout=5)#获取URLs,并返回应答对象
    print 'HTMLCode:',response.read()   #显示页面HTML代码
    print 'Ture URL:'+response.geturl() #获取页面的真实URL（重定向）
    print 'Info():',response.info()     #页面情况（字典）
