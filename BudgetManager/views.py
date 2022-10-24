from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.

def home(request):
	return render(request, 'home.html', {"nickname": "PKG"})

def add(request):
	num1 = int(request.POST['numberone'])
	num2 = int(request.POST['numbertwo'])
	ans = num1+num2
	return render(request, "result.html", {"res": ans})
