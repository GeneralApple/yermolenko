import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from numpy import array

def fit_func(x, a, power):
	return x ** power * a

x_data, y_data = [], []
with open(u'time_from_n.txt', 'r') as f:
	for line in f:
		x, y = line.split()
		x_data.append(float(x))
		y_data.append(float(y))

x_data, y_data = array(x_data), array(y_data)

fit_pars, _ = curve_fit(fit_func, x_data, y_data)

plt.plot(x_data, fit_func(x_data, fit_pars[0], fit_pars[1]), label=u'Fitted with x^power')
plt.plot(x_data, y_data, 'o', label=u'Raw data')
plt.title(u"Power={:.2f}".format(fit_pars[1]))
plt.legend()
plt.show()
