#!/bin/bash
touch clima                                         # crea el archivo clima
curl wttr.in/Guatemala >> clima && head -n 7 clima  # manda la informacion recopilada 
rm clima                                            # del link, la manda al archivo clima y elige 
                                                    #las primeras 7 lineas y muestra el archivo clima
