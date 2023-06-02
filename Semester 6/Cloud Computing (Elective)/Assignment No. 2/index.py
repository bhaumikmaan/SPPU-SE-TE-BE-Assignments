print 'Content-Type: text/plain'
print ''
print 'Hello there Friends'

for x in range(1,11):
	print '10 X ',x,' = ',10*x

#Write code for fibonacci series

first = 0 
second = 1

for x in range(1,8):
	c = first+second
	print c
	
	first = second
	second = c


	