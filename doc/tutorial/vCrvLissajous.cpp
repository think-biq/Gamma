/*	Gamma - Generic processing library
	See COPYRIGHT file for authors and license information
	
	Tutorial:		Visual
	Description:	Plot different harmonics of sine waves as (x,y) coordinates.
*/

#include "tutorial.h"

int main(int argc, char* argv[]){

	const int NP=256;				// Number of points in curve
	const int N1=31, N2=N1*N1;		// Size of graph
	float pixels[N2];				// Accumulation buffer

	SineR<> sineX, sineY;

	for(int k=1; k<4; ++k){
	for(int j=1; j<4; ++j){
	
		mem::zero(pixels, N2);
		sineX.set(float(j)/NP, 1);
		sineY.set(float(k)/NP, 1);
		
		printf("\nx:y = %d:%d\n\n", j,k);
		
		for(int i=0; i<NP; ++i){
			int ix = scl::posToInd( sineX(), N1);
			int iy = scl::posToInd(-sineY(), N1);
			pixels[iy*N1 + ix] += 0.125;
		}

		scl::print2D(pixels, N1, N1);
		printf("\n");
	}}

	return 0;
}
