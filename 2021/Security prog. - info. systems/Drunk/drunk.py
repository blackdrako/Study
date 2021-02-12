import random

def step(state):
	if state ==0 or state == 4: #
		return state 

r=random.random()
if state==1:
	if r<0.25:
		return 0
	else:
		return 2
elif state==2:
	if r<0.25:
		return 1
	elif r>0.75:
	return 3
	else:
	return 2
	else:
	if r<0.25:
	return 2
	else:
	return 4
	
n = 10000
life=[0]*n
averagelife=0
state=2
river=0
spear=0
for i in range(n):
	while state != 0 and state != 4:
		state=step(state)
		life[i]+=1
		if state ==0:
			river+=1
		else:
			spear+=1
		averagelife+=life[i]
		state=2
averagelife/=n
print(averagelife)
print(river/n)
print(spear/n)