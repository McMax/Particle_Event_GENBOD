#include "TObject.h"
#include "Particle.h"

Particle::Particle()
{
	fPid = 0;
	fPDGpid = 0;
	fCharge = 0;
	fPx = fPy = fPz = fMass = 0.;
}

Particle::Particle(UInt_t pid, Int_t pdgpid, Short_t charge, 
			Float_t px, Float_t py, Float_t pz,
			Float_t mass)
			
{
	fPid = pid;
	fPDGpid = pdgpid;
	fCharge = charge;

	fPx = px;
	fPy = py;
	fPz = pz;

	fMass = mass;
}

Particle::Particle(Particle& source_particle)
{
	fPid = source_particle.fPid;
	fPDGpid = source_particle.fPDGpid;
	fCharge = source_particle.fCharge;

	fPx = source_particle.fPx;
	fPy = source_particle.fPy;
	fPz = source_particle.fPz;

	fMass = source_particle.fMass;
}

Particle::Particle(Particle& source_particle, UInt_t pid)
{
	fPid = pid;
	fCharge = source_particle.fCharge;

	fPx = source_particle.fPx;
	fPy = source_particle.fPy;
	fPz = source_particle.fPz;

	fMass = source_particle.fMass;
}


Particle::~Particle()
{

}

ClassImp(Particle);
