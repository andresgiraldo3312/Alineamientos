#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

/*
    Clase que representa un dominio encontrado en una proteína
    usando la salida de hmmscan (Pfam/HMMER)
*/
class ProteinDomain {
    public:
        string familyId;
        string familyAccession;
        string clan;
    
        int envStart;
        int envEnd;
    
        int aliStart;
        int aliEnd;
    
        int modelStart;
        int modelEnd;
    
        double bitScore;
        double independentEvalue;
        double conditionalEvalue;
    
        string description;
    
        // Constructor
        ProteinDomain(
            string familyId,
            string familyAccession,
            string clan,
            int envStart,
            int envEnd,
            int aliStart,
            int aliEnd,
            int modelStart,
            int modelEnd,
            double bitScore,
            double independentEvalue,
            double conditionalEvalue,
            string description
        ) {
            this->familyId = familyId;
            this->familyAccession = familyAccession;
            this->clan = clan;
    
            this->envStart = envStart;
            this->envEnd = envEnd;
    
            this->aliStart = aliStart;
            this->aliEnd = aliEnd;
    
            this->modelStart = modelStart;
            this->modelEnd = modelEnd;
    
            this->bitScore = bitScore;
            this->independentEvalue = independentEvalue;
            this->conditionalEvalue = conditionalEvalue;
    
            this->description = description;
    }

    
    // Mostrar información del dominio
    void printInfo() const {
        cout << "====================================" << endl;
        cout << "Family ID        : " << familyId << endl;
        cout << "Accession        : " << familyAccession << endl;
        cout << "Clan             : " << clan << endl;

        cout << "Envelope Region  : "
             << envStart << " - " << envEnd << endl;

        cout << "Description      : "
             << description << endl;
    }
};


/*
    Clase que representa una proteína completa
    con múltiples dominios detectados por hmmscan
*/
class Protein {
    private:
        string proteinId;
        vector<ProteinDomain> domains;
    
    public:
        Protein(string proteinId) {
            this->proteinId = proteinId;
        }
    
        void addDomain(const ProteinDomain& domain) {
            domains.push_back(domain);
        }
    
        void printDomains() const {
            cout << "Protein: " << proteinId << endl;
            cout << "Number of domains: "
                 << domains.size() << endl;
    
            for (const auto& domain : domains) {
                domain.printInfo();
            }
        }
};


int main() {

    // Crear proteína
    Protein protein("Protein_X");

    // Agregar dominios encontrados por hmmscan

    protein.addDomain(
        ProteinDomain(
            "SH2",
            "PF00017",
            "CL0541",
            72,
            147,
            72,
            147,
            1,
            77,
            89.5,
            1.44e-25,
            2.98e-29,
            "SH2 domain"
        )
    );

    protein.addDomain(
        ProteinDomain(
            "SH3_1",
            "PF00018",
            "CL0010",
            12,
            58,
            12,
            58,
            1,
            48,
            52.1,
            4.88e-14,
            1.01e-17,
            "SH3 domain"
        )
    );

    protein.addDomain(
        ProteinDomain(
            "SH3_2",
            "PF07653",
            "CL0010",
            10,
            64,
            11,
            62,
            2,
            53,
            38.8,
            7.24e-10,
            1.50e-13,
            "Variant SH3 domain"
        )
    );

    // Mostrar información
    protein.printDomains();

    return 0;
}

