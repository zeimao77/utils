import msvcrt
import pyperclip
import random


##密码生成器
length = input("请输入需要的长度[默认12]：")
if len(length) == 0:
	length = 12
length = int(length)
print('0001 支持小写字母',end='\n')
print('0010 支持大写字母',end='\n')
print('0100 支持数字字符',end='\n')
print('1000 支持特殊字母',end='\n')
rangeVal = input("请输入二进制选择[默认0x0111]：0x")
rangePass = []
result = ''
if len(rangeVal) == 0:
	rangeVal = "0111"
if len(rangeVal) == 4:
	if(rangeVal[2] == '1'):
		rangePass = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
	if(rangeVal[3] == '1'):
		rangePass = rangePass + ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
	if(rangeVal[1] == '1'):
		rangePass = rangePass + ['1','2','3','4','5','6','7','8','9','0']
	if(rangeVal[0] == '1'):
		rangePass = rangePass + ['!','@','#','$','%','^','&','*','(',')']
	for i in range(0,length):
		result = result+random.choice(rangePass)
	print("结果:"+result)
	pyperclip.copy(result)
	print("[处理完毕;已将结果COPY到剪贴板]".center(30,'*'))
	print("请按任意键退出！")
	msvcrt.getch()
