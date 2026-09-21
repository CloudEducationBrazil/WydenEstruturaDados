import java.util.Arrays;

public class Main
{
	public static void main(String[] args) {
	    //ArrayList<Integer> seq   = new ArrayList<>();
	    //ArrayList<Integer> pilha = new ArrayList<>();
	    //ArrayList<Integer> topo  = new ArrayList<>();

        int[] seq   = new int[] {1, 2, 3, 4};
        int[] pilha = new int[4];
        int[] topo  = new int[4];
        
        for (int x = 0; x < 4; x++){
            pilha[x] = seq[x];        
        }
        //Arrays.fill(pilha, 90);
    	System.out.println(Arrays.toString(seq));
    
        int x = 3; 
        while (x > -1) {
    	    System.out.println(Arrays.to    String(pilha));
    	    pilha[x] = 0;
            topo = pilha;
    	    System.out.println("topo" + Arrays.toString(topo));
    	    x--;
        }
    }
}