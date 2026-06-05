#!/usr/local/bin/Rscript

source("descarga.r")
source("generadorDB.r")
source("alineamiento.r")



sequencias = list("P04637", "P38398","P68871", "P01308", "P02768", "P99999", "P00533", "P31749", "P01375", "Q9BYF1", "P42212", "P00698", "P02144", "P00582", "P0A7G6")





for(i in sequencias){
  print(i)
  try(descarga(i), silent = TRUE)
}


generadorDB()

for(i in sequencias){
  alineamiento(i) 
}

