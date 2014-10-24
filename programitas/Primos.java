import java.util.Date;
public class Primos {
	public static void main(String args[]){
		long ini = new Date().getTime();
		int primo = 2;
		while (primo <= 150000){
			int i = 1;
			int dividen = 0;
			while(i <= primo){
				if(primo % i == 0){
					dividen++;
				}
				i++;
			}
			if(dividen == 2){
				System.out.println("Primo encontrado: " + primo);
			}
			primo++;
		}
		long fin = new Date().getTime();
		System.out.println("El tiempo de ejecucion fue: " + (fin - ini) + " milisegundos");
	}
}