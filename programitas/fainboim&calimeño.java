public boolean internarNuevoPaciente(String nombreUnidad, String nombre, String apellido, int numeroIdentificacion, int edad){
	boolean esta = false;
	for (i = 0;i < listaDeInternados.length; i++) {
		if(listaDeInternados[i].getIdentificacion == numeroIdentificacion && esta == false){
			esta = true;
		}
	}
	if(esta){
		return false; //pues ya estaba ingresado.
	}else{ // si no estaba en la lista pasa a checkear las otras dos condiciones que pedian del metodo
		if(nombreUnidad.equals("Pediatria")){
			if(edad > 15){
				return false; // pues pacientes mayores a 15 años no pueden entrar a pediatria.
			}else{
				return true; // pues es menor de 15 años y no va pa pediatria.
			}
		}else if(nombreUnidad.equals("geriatria")){
			if(edad < 60){
				return false; // pues es menor de 60 y quiere entrar a geriatria
			}else{
				return true; //pues es mayor de 60 y va aentrar a geritria.
			}
		}
	}
}