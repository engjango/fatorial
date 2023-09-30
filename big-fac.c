/*************************************************************************
 * big-fac.c
 * 
 * Project:	Big-Numbers Factorial Simple Calculator
 * Author:	Janderson Silva
 * Blog:	artientista.blogspot.com
 * E-mail:	dparicarana@gmail.com 
 * 
 * THIS SOFTWARE IS PROVIDED BY AUTHORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE. 
 * 
 ************************************************************************/
 
#include <stdio.h>

// Número máximo de digitos do resultado (Máx. 10.000!)
#define MAX_DIGITS_NUMBER 40000 /* veja o arquivo: README.pdf */

/* Nota: veja que este algoritmo não eficaz quando pretende-se calcular
 * o fatorial de números desconhecidos, uma vez que para a correta execução
 * do presente algorítmo, faz-se necessário a correção da variável
 * MAX_DIGITS_NUMBER para a correta acomodação do resultado na memória.
 * */

int main()
{
	// Vetor com capacidade de armazenar "MAX_DIGITS_NUMBER" valores.
	char result[MAX_DIGITS_NUMBER]; 
	// Variáveis auxiliares
	int i, j, number, dcounter, carry, tmp;
		
	// Realiza a leitura do número
	printf("Factorial Simple Calculator\n\n");
	printf("Type a number (Example: 10000): ");
	scanf("%d", &number);
		
	// Inicializa o vetor com apenas 1 digito, o digito 1
	result[0] = 1;
		
	// Inicializa o contador de digitos do resultado, isto é,
	// o resultado já contém um digito - o digito 1 acima.
	dcounter = 1;
	
	// Inicializa a variável de transporte com o valor zero
	carry = 0;
		
	// Imprime uma linha em branco
	puts("");
	
	for (i = 1; i <= number; i++)
	{
		for (j = 0; j < dcounter; j++)
		{
			// tmp contém o produto "digito * digito"
			tmp = result[j] * i + carry;
			// result[j] contém o digito armazenado na posição j
			result[j] = tmp % 10;			
			// carry contém o valor de transporte que será armazenado
			// nos últimos índices
			carry = tmp / 10;
		}
			
		// Laço de repetição que armazena o valor de transporte no vetor
		while(carry > 0)
		{
			result[dcounter] = carry % 10;
			carry /= 10;
			dcounter++;
		}
		
		// Imprime uma mensagem informando quantos digitos foram 
		// calculados até o momento
		printf("\r%d calculed digits...", dcounter);
	}
		
	// Imprime uma linha em branco
	puts("");
		
	// Imprime o resultado da operação
	printf("\nfactorial of %d is equal to:\n\n", number);
	for (i = dcounter - 1; i >= 0; i--)
	{
		printf("%d", result[i]);
	}
	
	// finaliza a função principal corretamente
	return(0);
}
