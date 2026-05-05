#include "student_api.h"

int student_pair_syscall(struct syscall_pairer *pairer,
                         const struct syscall_event *ev,
                         struct syscall_event *out)
{

    //se ev->entering for 1 ou seja for entrada
    if (ev->entering)
    {
        pairer->entry = *ev; //guarda as info q ta no ev na variavel entry q tb é do tipo da struct syscall_event
        pairer->has_entry = 1; //para simbolizar que entrou
        return 0; //só fez a entrada
    } else {
        if (!pairer->has_entry) //saiu sem ter entrado, logo evento inválido
        {
            return -1;
        }

        //se chegou aqui ele entrou e saiu coretamente da syscall
        *out = pairer->entry; //guarda as mesmas info de pairer pq pid e outras coisas n mudam

        out->ret = ev->ret;
        out->entering = 0; //precisa conferir na montagem do student_format_event se faz sentido trocar para 0 ou se é inútil

        //limpa o has_entry para garantir que nao vai entrar no if de evento inválido erroneamente
        pairer->has_entry = 0;

        return 1;
    }

    /*
     * TODO Semana 2:
     *
     * O runtime chama esta funcao duas vezes para cada syscall:
     *
     *   1. uma vez antes da syscall executar
     *   2. uma vez depois da syscall terminar
     *
     * Na primeira parada, os argumentos estao disponiveis.
     * Na segunda parada, o retorno esta disponivel.
     *
     * Seu trabalho e produzir um evento completo apenas quando ja existirem
     * as duas metades da syscall.
     *
     * Dicas:
     * - ev->entering == 1 indica entrada de syscall.
     * - ev->entering == 0 indica saida de syscall.
     * - para comecar, assuma apenas um processo monitorado.
     *
     * Retorne:
     *   1 se out contem uma syscall completa
     *   0 se ainda nao ha syscall completa
     *  -1 se a sequencia de eventos parece invalida
     */
    return 0;
}
