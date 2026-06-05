


# Constructor
Proteina <- function(file) {
    datos = read.csv(file = file,header = TRUE, sep = "\t")
    class(datos) <- "Proteina"
  return(datos)
}


# Método print para la clase Persona
print.Proteina <- function(x, ...) {
  class(x) <- NULL
  for(i in 1:length(x$Family.id)){

    print(x$Family.id[i])
    print(rep("+",(as.numeric(x$Env..End[i])-as.numeric(x$Env..Start[i]))))

  }

}



#Ndominios.Proteina <- function() {
#  print(datos)
#}

# Crear un objeto
p1 <- Proteina("../Alineamientos/ejemplo_hmmscan.tsv")





