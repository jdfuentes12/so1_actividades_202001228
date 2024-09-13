# Control de accesos

## _Parte 1: Gestión de usuarios_

### Creacion de usuarios

El código para agregar un usuario es `useradd nombre_de_usuario`. En este caso se agregaron 3 usuario que son los siguientes:

- usuario1
- usuario2
- usuario3
  <br><br>
  ![image](https://github.com/user-attachments/assets/2b5d880a-f0e3-44de-92ae-caa76ab8b2ac)

### Verificacion de usuarios en el sistema

El comando para verificar si un usuario existe en el sistema es `cat /etc/passwd`. En las ultimas lines se podra observar que los usuarios fueron agregados con exito.
<br><br>
![image](https://github.com/user-attachments/assets/0daa1ba5-921d-4dcd-b711-8f5d89e329b9)

### Asignacion de contraseñas

Como ya se crearon los usuario se procede a colocarles la contraseña a cada uno de ellos. Con el comando `passwd nombre_de_usuario`, tomando en cuenta que se tiene que colocar 2 veces la contraseña para verificar que coincidan. Tomando en cuenta que tiene que tener ciertos caracteres para que el sistema lo reconozca.

- Usuario1 - Contraseña: 3ix7081CTTud
- Usuario2 - Contraseña: d9ZA5zP4o8a9
- Usuario3 - Contraseña: i4bIRAGs71u6
  <br><br>
  ![image](https://github.com/user-attachments/assets/820bae22-be2c-4748-ba58-a27a5080f1f5)

### Informacion de Usuarios

Para saber la informacion de un usuario se coloca el siguiente comando `id nombre_de_usuario`, sabiendo que no se revelara la contraseña. En este caso se mostrará la informacion del "usuario1".
<br><br>
![image](https://github.com/user-attachments/assets/70a9a68b-c6ea-4262-9a6d-ea3b614ff756)

### Elimnacion de usuarios

Para eliminar un usuario se coloca el comando `userdel nombre_de_usuario`. Pero si se quiere eliminar tambien el directorio se tiene que colocar el comando `userdel -r nombre_de_usuario`. La diferencia de estos es que si se quiere crear un usuario con el mismo nombre no se podra ya que tendra el directorio registrado del usuario. En este caso conservaremos el directorio en el sistema del usuario3.
<br><br>
![image](https://github.com/user-attachments/assets/225fc895-b0df-4f2b-9b54-5221adeb6a46)

## _Parte 2: Gestión de grupos_

### Creacion de gurpos

Para la creacion de grupos en linux tenemos que tomar encuenta el siguiente comando `groupadd nombre_del_grupo`.
<br>
![image](https://github.com/user-attachments/assets/cd212b2a-3dd1-4cf3-9a3a-3bb6d85ed4f4)
<br><br>
Si no estamos seguros de los grupos que hemos creado con este comando podremos ver todos los grupos que hay en nuestro sistema `cat /etc/group`
<br>
![image](https://github.com/user-attachments/assets/4fa94c72-1138-4b71-ab15-8d21188c60ff)
<br>
Como se puede ver en la ultima linea esta el grupo que se ha creado.

### Agregar Usuarios a Grupos

Para agregar a un usuario a un grupo se tiene que colocar el siguiente comando `sudo usermod -aG nombre_del_grupo nombre_del_usuario`.
<br>
![image](https://github.com/user-attachments/assets/86a10a06-6264-4f75-bb07-29f8f2e4e030)

<br>

### Verificcion de membresía

Para verificar si el usuario fue agregado con exito al grupo se coloca le siguiente comando `grep nombre_del_grupo /etc/group`.
<br>
![image](https://github.com/user-attachments/assets/86a10a06-6264-4f75-bb07-29f8f2e4e030)

### Eliminacion de grupos

Para eliminar un grupo se coloca el siguiente comando `sudo groupdel nombre_del_grupo`.
<br>
![image](https://github.com/user-attachments/assets/2913e0ab-c55a-43fd-bfa2-c6fdf0341b38)

## _Parte 3: Gestión de permisos_

### Creacion de Arcivos y Directorios

![image](https://github.com/user-attachments/assets/18d13136-b8c3-4ed1-866b-b0c3750043b5)

### Verificar permisos

![image](https://github.com/user-attachments/assets/57f50833-50c3-4cb0-b0c0-41c9e6e13c1e)

### Modificacr permisos usando 'chmod' con Modo Simbolico

![image](https://github.com/user-attachments/assets/17f3a1b8-01f0-43d6-8ed2-b5b7f5870267)

### Modificar Permisos usando `chmod` con Modo Simbólico

![image](https://github.com/user-attachments/assets/81d314da-6c0f-4a8b-a993-23b374135c5a)

### Cambiar el grupo propietario

![image](https://github.com/user-attachments/assets/843527fb-c0f2-4320-a0fe-2ff7290a020a)

### Configurar permisos de directorio

![image](https://github.com/user-attachments/assets/a8560b30-8095-4767-a2df-c1914ecf4b13)

### Comprobacion de acceso

![image](https://github.com/user-attachments/assets/5d4d9faf-cb94-430d-a8b4-30239d56ad68)

### Verificacion Final

![image](https://github.com/user-attachments/assets/37545da4-30a7-4532-aa5a-72b839bdc796)

# _Preguntas_

### ¿Por qué es importante gestionar correctamente los usuarios y permisos en un sistema operativo?

Para tener mejor seguridad y privacidad de los archivos que tenemos en nuestro usuario, esto nos permite que usuario ajenos puedan modificar y afectar en rendimiento del sistema operavo o de algun archivo en especifico.

### ¿Qué otros comandos o técnicas conocen para gestionar permisos en Linux?

Actualmente ando indagando en Linux, porque mi sistema operativo por defecto habia sido Windows por mucho tiempo.
