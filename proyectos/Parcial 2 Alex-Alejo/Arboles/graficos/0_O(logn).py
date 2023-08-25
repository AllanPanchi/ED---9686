import matplotlib.pyplot as plt
import numpy as np

# Definir un rango de valores de entrada
x = np.linspace(1, 10, 100)  # Cambiar el rango para evitar log(0)

# Definir la función O(log n)
def o_log_n(x):
    return np.log2(x)

# Crear la figura y el gráfico con fondo negro
fig = plt.figure(figsize=(8, 6), facecolor='black')  # Cambiar el color de fondo de la ventana
ax = fig.add_subplot(1, 1, 1, facecolor='black')  # Cambiar el color de fondo del plano x-y
ax.plot(x, o_log_n(x), label='O(log n)', color='yellow')  # Cambiar el color de la línea

# Personalizar los límites de los ejes
ax.set_xlim(1, 10)  # Establecer los límites del eje x
ax.set_ylim(0, 5)   # Establecer los límites del eje y

# Personalizar el gráfico
ax.set_title('Función O(log n)', color='white')  # Cambiar el color del título
ax.set_xlabel('Tamaño de entrada', color='white')  # Cambiar el color del label x
ax.set_ylabel('Operaciones', color='white')  # Cambiar el color del label y
ax.legend()
#ax.grid(color='white', linestyle='--', linewidth=0.5)  # Cambiar el color de las líneas de la grilla

# Cambiar el color de los números en los ejes y la línea encima de los números del eje x
ax.xaxis.label.set_color('white')
ax.yaxis.label.set_color('white')
ax.tick_params(axis='x', colors='white')
ax.tick_params(axis='y', colors='white')
ax.tick_params(axis='x', which='both', width=0, color='white')  # Configurar línea encima de números de eje x
ax.tick_params(axis='y', which='both', width=0, color='white')  # Configurar línea encima de números de eje x

# Agregar las líneas de los ejes x e y
ax.axhline(0, color='white', linewidth=0.95)  # Línea del eje x
ax.axvline(0, color='white', linewidth=0.95)  # Línea del eje y

ax.axvline(0, color='white', linewidth=0.8)  # Línea vertical en el eje y


# Cambiar el color de las leyendas
leg = ax.legend()
for text in leg.get_texts():
    text.set_color('white')

# Mostrar el gráfico
plt.show()
