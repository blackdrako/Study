#include <mpi.h>
#include <stdio.h>
int main(int argc, char* argv[]) {
    	int ProcNum, ProcRank, RecvRank;
	MPI_Status Status; 
     MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
	MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
	if ( ProcRank == 0 ) { // Действия для процесса 0
		printf ("\n Hello from process %3d", ProcRank);
		int i;
		for (i=1; i < ProcNum; i++ ) {
		    MPI_Recv(&RecvRank, 1, MPI_INT,i,
				MPI_ANY_TAG, MPI_COMM_WORLD, &Status);
		    printf("\n Hello from process %3d", RecvRank);
		}
	}
	else // Действия для всех процессов, кроме процесса 0
	MPI_Send(&ProcRank,1,MPI_INT,0,0,MPI_COMM_WORLD);
	// Завершение работы
	MPI_Finalize();
	return 0; 
}