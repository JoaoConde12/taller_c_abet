# taller_c_abet

La fundación Salud para Todos es una organización no gubernamental que financia hasta un 90% de los tratamientos de pacientes a través de donaciones de empresas privadas y población civil. Debido a la pandemia producida por el Covid-19 ha tenido un decremento de sus ingresos haciendo que muchos de sus tratamientos ya no sean financiados parcialmente o en su totalidad. Por tal motivo, con la finalidad de brindar los tratamientos completos a sus pacientes la fundación con ayuda de entes internacionales implementó una unidad médica, la cual es gestionada y administrada por la misma fundación. Sin embargo, una vez que fue puesta en marcha, la fundación se encontró con los siguientes problemas:

  - El agendamiento de citas el cual es realizado manualmente por el personal de la fundación es deficiente, produciéndose una pérdida de información y confusión en las citas       agendadas.
  - La farmacia no cuenta con un sistema que les permita llevar un control estricto del inventario de medicinas, así como del despacho de recetas médicas a los pacientes.
  - No se posee un sistema de contable que permita registrar los ingresos y egresos económicos de la unidad médica, dificultando el correcto seguimiento de los flujos de caja, lo cual a la larga puede causar el cierre de la unidad médica.

En este taller se llegó a la conclusión que la prioridad de estas fundaciones siempre será el que sus pacientes puedan gozar de un excelente servicio y sus enfermedades sean atendidas correctamente, por ende, es importante solucionar el sistema de agendamiento de citas. Algunos de los nudos críticos que se identificaron fueron:

#### 1) La pérdida de información

Al seragendadas las citas de forma manual esto permite que sea más probable que exista algún error a la hora del agendamiento. Esto se debe a varias causas, por ejemplo: Las citas se almacenarían en archivos en físico y es más probable que se pierdan; otro caso podría ser que al anotar la información del paciente a puño y letra quizás otra persona (por ejemplo, un médico) no entienda correctamente los datos del paciente que anotó el/la secretario/a y por ende haya confusión a la hora de la consulta médica.

#### 2) La ineficiencia del proceso de agendamiento

Evidentemente el escribir de forma manual todos los datos del paciente es mucho más lento y, por ende, causa que se demore mucho más el agendar la cita. Además, que luego de hacer la ficha del paciente este tiene que guardarlo en algún archivo lo cual demora más este proceso y que quizás los pacientes que desean agendar una cita en la unidad médica tengan que esperar más tiempo del que deberían.

#### 3) La disponibilidad de horarios del doctor

Esto se debe a que al estar anotado las fechas y horas de las citas de forma manual es mucho más lento y confuso el saber en qué horario un doctor está libre para poder agendar una cita. Además, en caso de haber anotado incorrectamente un horario esto puede desembocar en que se choquen los horarios con los pacientes lo cual generaría una clara inconformidad con el servicio que ofrece la unidad médica.

## Solución de los nudos críticos

Para solucionar el primer nudo crítico, se puede pensar en la creación de un software que permita llevar el control del agendamiento de citas, en él se podrá registrar tanto la información de los pacientes como de sus horarios. Además, estos se guardarían en la computadora por lo que es mucho más fácil tener almacenada la información dentro de un dispositivo que en varios archivos.

A través de este programa también se resolvería el segundo y tercer nudo crítico, ya que todo este proceso se automatizaría de mejor manera y con ello también se haría más eficiente, ya que los pacientes deberán esperar menos para agendar su cita y no perderán tanto tiempo en este proceso. Además, que se podrá consultar los horarios de los doctores con solo presionar unos botones.

## Visualización del programa:

Primero, el programa imprime un menú con las opciones que puede escoger el usuario: agendar cita, editar cita (moverla), eliminar cita, visulizar horarios y salir del programa, todo esto desde la terminal o consola.

![image](https://github.com/JoaoConde12/taller_c_abet/assets/132232545/85b064dc-59bc-4b5f-a80e-8d336f3093b6)

En cada opción del programa (a excepción de la quinta, que es para salir del programa) se muestran todos los doctores de la unidad médica, los cuales se encuentra en archivo .txt y el usuario debe escoger un doctor para acceder a su horario de citas y que pueda, agendar una cita, editar o mover una cita, eliminar una cita, o simplemente visualizar su horario.

![image](https://github.com/JoaoConde12/taller_c_abet/assets/132232545/d1a99b6c-844a-4aa2-b854-e2b60022cfe2)

A continuación se mostrará cada opción en más detalle:

#### Agendar cita:

Una vez seleccionado el doctor, se desplegará su horario y en él se podrá visualizar en que día y hora tiene una cita agendada. Luego se le pedirá al usuario que inserte el ID, el cual es el número de línea el cual correspondería a la hora, por ejemplo el ID 1 corresponde a la hora de 7:00 am - 7:20 am. Después de seleccionar el ID, se le pide que inserte el número del día, ejemplo:

  - Lunes = 1
  - Martes = 2
  - Miércoles = 3
  - Jueves = 4
  - Viernes = 5
  - Sábado = 6
  - Domingo = 7

Y en caso de que en el ID (hora) y día que se seleccionó, no haya una cita agendada, se agendará una cita para esa fecha. En el caso de que esa fecha esté ocupada, no se podrá agendar la cita y se volverá al menú principal

![image](https://github.com/JoaoConde12/taller_c_abet/assets/132232545/294d797f-98ed-4a81-8a37-d47b06e5cb2f)

#### Editar cita:

Esta es una opción que nos permite mover una cita que ya se encuentre agendada de una fecha a otra, luego de seleccionar al doctor primero se nos pide que insertemos el ID y el día de la cita que queremos mover, luego se nos pide que se inserte el ID y el día de la fecha en donde queremos insertar la cita que queremos mover. En caso de que el ID y el día que seleccionamos primero (el de la fecha que se quiere mover) no tenga una cita agendada, el programa nos lo hará saber diciendo que en esa fecha no hay una cita agendada. Y en el caso de que el ID y el día de la fecha en donde se quiere insertar la cita que queremos mover esté ocupado, el programa también nos lo hará saber.

Pero en caso de que todo esté correctamente, se moverá la cita de que queríamos a la nueva fecha que seleccionamos

![image](https://github.com/JoaoConde12/taller_c_abet/assets/132232545/991bce07-012d-4f93-9df8-6376ec87ffa0)

#### Eliminar cita

Este funciona de manera similar que la opción para agendar cita, nos pide el ID y día de la cita que se quiere eliminar y en caso de que la fecha que inserte el usuario corresponda a una donde no haya una cita agendada, se imprimirá en pantalla que no hay una cita agendada y se volverá al menú principal. Y en el caso de que si se encuentre una cita en la fecha que se insertó, esta se eliminará

![image](https://github.com/JoaoConde12/taller_c_abet/assets/132232545/f5d9264e-a51a-4c56-8fb8-65c9413548b7)

#### Visualizar horario:

La opción más simple, en esta después de seleccionar al doctor que se desea, se imprimirá su horario y luego se vuelve al menú principal

![image](https://github.com/JoaoConde12/taller_c_abet/assets/132232545/d97ced17-6b73-45f9-8c54-fa778ac58ec7)

## Conclusiones y recomendaciones

Como conclusiones generales, es un programa sencillo pero logra solucionar los nudos críticos del programa, ya que hay un manejo mucho más sencillo a la hora de agendar cita. Estas se almacenan en archivos .txt donde es mucho más fácil acceder a esa información y visualizarla que si se agendara de forma manual, con esto también se reducen las posibilidades de que haya confusiones o pérdidas. También logra hacer que se agilice mucho más el proceso de agendamiento de una cita, ya que para agendar una basta con insertar unos cuantos números para seleccionar el doctor y escoger la fecha en la que se desea agendar su cita; con esto se reduce de forma significativa los tiempos en los que una persona se demoraría si se hace este proceso de forma manual. Finalmente es mucho mejor visualizar los horarios de esta forma que si se anotara en hoja y papel, como se ve en las imágenes anteriores, se imprimer correctamente el horario y es claro en que hora y día hay una cita agendada y en cuales no, esto facilita la lectura de horarios para las personas que se encarguen de agendar las citas

Como recomendaciones, se debería dar una pequeña capacitación al personal de la unidad médica que esté encargado del proceso de agendamiento de citas, ya que si se desea agregar un nuevo doctor, estos se deben guardar en el archivo doctores.txt de forma alfabética. Adicional a esto, se debe crear su propio archivo .txt donde se encontrará su horario personal. Algunas de las mejoras que se podría hacer es añadir una opción para que al acabar la semana, se puedan reiniciar todos los horarios, es decir, que no se muestre ninguna cita agendada, ya que hasta ahora este proceso se debe hacer de forma manual. Por último, sería idóneo que los archivos con los nombres de los doctores y sus horarios se suban a una base de datos, ya que de esta manera en caso de que a la computadora donde se registren los horarios le ocurra alguna falla, estos archivos no se verían afectados.
