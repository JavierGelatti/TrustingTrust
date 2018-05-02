# Hacking en compiladores: Revisitando "Reflections on Trusting Trust"
Repositorio con el código de la charla realizada en el marco del Congreso Internacional de Seguridad Informática "Tucumán Hack Weekend" 2018, organizado por la Rama Estudiantil IEEE Tucumán, en la Universidad Tecnológica Nacional, Facultad Regional Tucumán.

## Aclaración
El objetivo de esta charla es producir una reflexión sobre el rol de la confianza en el uso y desarrollo de sistemas, y los desafíos que existen dentro de la seguridad informática, mostrando un tipo de ataque conocido (publicado en un paper de 1984), además de otros temas interesantes (como programas que se auto-reproducen, o definiciones auto-referenciadas dentro del compilador).

No hay que dejar de tener en cuenta las responsabilidades que tenemos como profesionales, y los aspectos éticos que existen cuando se realizan actividades de este tipo. Una de las ideas que se buscaron transmitir con la charla tiene que ver con la manera en la que las actividades que realizamos están basadas en la confianza. Al ejecutar cualquier tipo de ataque, se está aprovechando la confianza de las demás personas, lo que es muy peligroso para toda la comunidad.

## Requisitos
Para poder ejecutar los ejemplos, el compilador `gcc` tiene que estar instalado en el sistema.

## Video
> https://youtu.be/hxJRzQeoYTI

## Diapositivas
> https://www.slideshare.net/secret/JzmoWCP1wTMjNB

## Referencias
1. Reflections on Trusting Trust, Ken Thompson (1984)
https://www.ece.cmu.edu/~ganger/712.fall02/papers/p761-thompson.pdf
2. A talk about Reflections on Trusting Trust, Yeo Kheng Meng (2017)
https://github.com/yeokm1/reflections-on-trusting-trust 
3. Fully Countering Trusting Trust through Diverse Double-Compiling, David A. Wheeler (2009)
https://www.dwheeler.com/trusting-trust/dissertation/wheeler-trusting-trust-ddc.pdf 
4. Critique of Diverse Double-Compiling, Paul Jakma (2010)
https://pjakma.files.wordpress.com/2010/09/critique-ddc.pdf

Los ejemplos de Quine fueron obtenidos de:
1. Smalltalk
http://forum.world.st/Smalltalk-Quine-tp4640396p4640464.html
2. Ruby y SQL
https://en.wikipedia.org/wiki/Quine_(computing)#Examples
