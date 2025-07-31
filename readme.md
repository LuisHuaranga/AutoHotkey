
## COMPILAR Y CREA EJECUTABLE CON CONSOLA
g++ main.cpp -o hook.exe -luser32 -Wl,--subsystem,console



## COMPILAR Y CREA EJECUTABLE SIN CONSOLA
g++ main.cpp -o hook.exe -luser32 -Wl,--subsystem,windows

##HOLI