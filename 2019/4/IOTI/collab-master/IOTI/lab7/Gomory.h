#pragma once
#include "SimplexArtificial.h"
#include "ClarificationOfRatings.h"

class Gomory{
	//SimplexArtificial S;
	Frac_matr M;
	Frac_arr Z;
	long m, n;
public:
	Gomory(long m, long n) : m(m), n(n), M(m , n), Z(n){};
	void Input();
	bool check_int();
	bool isPsevdo();
	void GomoryStep();
	void addRestrictions();
	/*void copySimpToClar(ClarSimplexTable &C, SimplexArtificial& S);
	void copyClarToSimp(ClarSimplexTable& C, SimplexArtificial& S);*/
	void copyToSimp(SimplexArtificial& S);
	void copyFromSimp(SimplexArtificial& S);
	void copyToClar(ClarSimplexTable& C);
	void copyFromClar(ClarSimplexTable& C);
	void GomorySolution();
	void outputSolution(SimplexArtificial& S);
	void outputSolution(ClarSimplexTable& C);
};

