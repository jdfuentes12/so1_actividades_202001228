# Tipos de Kernel

## Monolítico

Todo el código necesario para que el sistema operativo funcione reside en el mismo espacio de memoria y se ejecuta en modo kernel.

## Microkernel

Solo las funciones más básicas del sistema operativo, como la comunicación entre processi y la gestión de la memoria, se ejecutan en modo kernel. Otras funcionalidades, como los controladores de dispositivos y los sistemas de archivos, se ejecutan en modo usuario.

## Kernel Híbrido

Combina elementos de los kernel monoliticos y crokernels. Manteniendo la estructura básica de un kernel monolítico, pero incorpora elementos modulares como en elos microkernels, permitieno que algunas operaciones se realicen fuera del espacio del kernel.

## Exokernel

Proporciona un mecanismo mínimo para la gestión de recursos, dejando la mayor parte de trabajo a las aplicaciones en modo usuario.

# User Mode vs Kernel Mode

Son dos modos de operación del procesador que permiten al sistema operativo y las aplicaciones gestionar de manera segura y eficiente los recursos del sistema.

## User Mode

Es el modo en el que se ejecutan las aplicaciones de usuario. Tiene acceso restringido a los recursoso del sistema y debe interactuar con el kernel para realizar operaciones que requiere un mayor nivel de privilegio.

## Kernel Mode

Es el modo en el que se ejecuta el núcleo del sistema operativo y tienen acceso completo a todos los recursos del sistema, incluidos el hardware y la memoria.

# Interrruptions vs Traps

Son mecanismos fudamentales en los sistemas operativos que permiten manejar eventos tanto de hardware como de software de manera eficiente.

## Interruptions

Son señales enviadas al procesador pro dispositivos de hardware para indicar que se ha producido un evento que requiere atención inmediata.

## Traps

Son un tipo de específico de interrupción que generalmente son generadas por el software para invocar una operación especifica del sistema operativo, como una llamada al sistemas de una excepción.
