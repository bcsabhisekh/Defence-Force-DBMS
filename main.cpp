
//com1 contains sec1, sec 2 and sec3
//com2 contains sec 4, sec5 and sec6
//we have to make function to initialize --> army_section.bin file with the weapons and soldiers.
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ios;
using std::ofstream;
using std::string;
using std::vector;

//functions used in the program
void add_user(void);
void add_cds_details(void);
void add_army_section_detail(void);
void cds_login(void);
void cds_field(void);
void main_menu();
void add_war_details(void);
void army_field(void);
void sepoy_login(void);
void lieu_login(void);
void major_login();
void general_login(void);
void add_personel(string post_name);
void modify_personel(string post_name);
void delete_personel(string post_name);
void army_personal_dashboard(void);

//functions for airforce
void add_airforce_user(); //for temporary adding airforce personel
void add_airforce_personel(string post_name);
void airforce_field();
void air_personal_dashboard(void);
void flight_lieu_login();
void squad_leader_login();
void air_chief_marshal_login();
void aircraftman_login();
void modify_airforce_personel(string post_name);
void delete_airforce_personel(string post_name);
void add_airforce_section_detail(void);

//common functions
void war_details(void);
void display_war_history();

//class definitions
class date //for storing dates
{
    private:
        unsigned day, month, year;

    public:
        void getter_date()
        {
            cout << "Enter the day/month/year separated by space: ";
            cin >> day >> month >> year;
        }
        void display_date()
        {
            cout << day << "-" << month << "-" << year;
        }
};
class cds //Chief of Defence Staff    //only one object should be made
{
    //he can view everythin
    private:
        string cds_id;
        string name;
        string username;
        string password;
        date date_of_birth;   //containership  //age can be calculated by this
        date date_of_joining; //containership
    public:
        void getter_cds()
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Date of Birth:  ";
            date_of_birth.getter_date();
            cout << "Date of Joining: ";
            date_of_joining.getter_date();
            flag1:
            cout << "Set your password:\n";
            cout << "Enter new password: ";
            string pass1, pass2;
            cin >> pass1;
            cout << "Confirm new password: ";
            cin >> pass2;
            if (pass1 == pass2)
            {
                this->password = pass1;
            }
            else
            {
                cout << "\nPassword Not Matched\n";
                goto flag1;
            }
        }
        void display_cds()
        {
            cout << " \nName : " << name;
            cout << " \nDate Of Birth : ";
            date_of_birth.display_date();
            cout << " \nDate Of Joining : ";
            date_of_joining.display_date();
            cout << endl;
        }
        string ret_username_cds(void)
        {
        return username;
        }
        void set_password_cds(string pass)
        {
        this->password = pass;
        }
        string ret_password_cds(void)
        {
        return password;
        }
};

class sepoy
{
    private:
        string sepoy_id; //only for sepoys and hence not inheritable
    protected:
        string name;
        date date_of_birth;   //containership  //age can be calculated by this
        date date_of_joining; //containership
        string password;      //for storing password

    private: //not inheritable information
        string sepoy_section_id;

    public:
        void getter()
        {
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Date of Birth:  ";
            date_of_birth.getter_date();
            cout << "Date of Joining: ";
            date_of_joining.getter_date();
        flag1:
            cout << "Set your password:\n";
            cout << "Enter new password: ";
            string pass1, pass2;
            cin >> pass1;
            cout << "Confirm new password: ";
            cin >> pass2;
            if (pass1 == pass2)
            {
                set_password(pass2);
            }
            else
            {
                cout << "\nPassword Not Matched\n";
                goto flag1;
            }
        }

        void getter_sepoy()   //takes the information input for sepoy
        {
            cout << "Enter Sepoy Id: ";
            cin >> sepoy_id;
            getter();
            cout << "Enter Section Id(sec1 to sec6): "; //there are 6 sections from sec1 to sec6. This means there should be only 6 objects created into the section.bin file
            cin >> sepoy_section_id;                    //sec1, sec2, sec3, ..., sec6
        }
        void display()
        {
            cout <<"\nName : " << name;
            cout <<"\nDate Of Birth : ";
            date_of_birth.display_date();
            cout <<"\nDate Of Joining : ";
            date_of_joining.display_date();
        }
        void display_sepoy()
        {
            cout <<"\nSepoy ID : " << sepoy_id;
            display();
            cout << "\nSection ID : " <<sepoy_section_id;

        }
        void set_password(string pass)
        {
            this->password = pass;
        }
        string get_password()
        {
            return password;
        }
        string ret_sep_id()
        {
            return sepoy_id;
        }
        string ret_sep_name()
        {
            return name;
        }
        int ret_sepoy_sec_id()
        {
            if (sepoy_section_id == "sec1")
                return 1;
            else if (sepoy_section_id == "sec2")
                return 2;
            else if (sepoy_section_id == "sec3")
                return 3;
            else if (sepoy_section_id == "sec4")
                return 4;
            else if (sepoy_section_id == "sec5")
                return 5;
            else if (sepoy_section_id == "sec6")
                return 6;
            return -1;
        }
        void modify()
        {
            cout << "Enter modified Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Modified Date of Birth:  ";
            date_of_birth.getter_date();
            cout << "Modified Date of Joining: ";
            date_of_joining.getter_date();
        }
        void modify_sepoy()
        {
            modify();
            cout << "Enter modified section Id: ";
            cin >> sepoy_section_id;
        }
        
};

class lieutenant : public sepoy
{
    private:
        string lieutenant_id; //every lieutenent has the unique id
        string section_id; //the id of the section he is leading
    public:
        void getter_lieutenant()
        {
            cout << "Enter Lieutenent ID: ";
            cin >> lieutenant_id;
            sepoy::getter();
            cout << "Enter Section ID: ";
            cin >> section_id;
        }
        void display_lieutenant()
        {
            cout << "\nLieutenant Id: " << lieutenant_id;
            sepoy::display();
            cout << "\nSection Id: " << section_id;
        }
        string ret_lieu_id()
        {
            return lieutenant_id;
        }

        void modify_lieutenant()
        {
            sepoy::modify();
            cout << "Enter modified section Id: ";
            cin >> this->section_id;
        }
};

class Major : public lieutenant //head of a company
{
    private:
        string major_id;
        string company_id;
        // string platoon_id;

    public:
        void getter_major()
        {
            cout << "Enter Major Id: ";
            cin >> major_id;
            sepoy::getter();
            cout << "Enter company id(com1/com2): ";
            cin >> company_id;
        }
        void display_major()
        {
            cout <<"\nMajor ID: " << major_id;
            sepoy::display();
            cout <<"\nCompany Id: " << company_id;
            cout<<endl;
        };

        string ret_maj_id()
        {
            return major_id;
        }
        void modify_major()
        {
            sepoy::modify();
            cout << "Enter modified company Id: ";
            cin >> this->company_id;
        }
};

class section_army
{
    protected:
        unsigned num_sepoys;
        string section_id;
        string lieutenant_id;
        unsigned num_gun;
        unsigned num_tank;
        unsigned num_mortar;
        unsigned num_combat_shotgun;

    public:
        void operator++(int) //adds a sepoys into the required section
        {
            this->num_sepoys++ ;
        }
        void getter_section_army()
        {
            cout<<"Enter Number of sepoy: ";
            cin>>num_sepoys;
            cout << "Enter section Id: ";
            cin.ignore();
            cin >> section_id;
            cout << "Enter lieutenant Id: ";
            cin >> lieutenant_id;
            cout << "Enter numbers of guns: ";
            cin >> num_gun;
            cout << "Enter number of tanks: ";
            cin >> num_tank;
            cout << "Enter number of mortars: ";
            cin >> num_mortar;
            cout << "Enter number of combat shotguns: ";
            cin >> num_combat_shotgun;
        }

        void print_section_info() 
        {
            cout<<"\nNumber of Sepoy: "<<num_sepoys<<endl;
            cout << " \nLieutenant Id: " << lieutenant_id << endl;
        }
        //prints the weapon information
        void print_section_weapon_info() 
        {
            cout << "The weapons alloted to this section are:-\n";
            cout << "No. of Guns: " << num_gun << endl;
            cout << "No. of Tanks: " << num_tank << endl;
            cout << "No. of Mortars: " << num_mortar << endl;
            cout << "No. of Combat Shotguns: " << num_combat_shotgun << endl;
        }
};

// Army_General can access all the class using multiple inheritance
//can edit the details of any employee 
// can modify the war and weapons data
class general : public Major 
{
private:
    string general_username;
public:
    friend class cds;
    void getter_general() //temporary for first entry of General 
    {
        cout << "Enter General Username:  ";
        cin >> general_username;
        sepoy::getter();
    }
    void display_general()
    {
        cout << "\nUsername: " << general_username;
        sepoy::display();
    }
    string ret_gene_username() //returns the username of general which is equivalent of sepoy_id for a sepoy
    {
        return general_username;
    }
    string ret_gen_name() 
    {
        return name;
    }
};


//Airforce Personel
//--------------------

class aircraftman
{
    private:
        string aircraftman_id; //only for airman and hence not inheritable
    protected:
        string name;
        date date_of_birth;   //containership  //age can be calculated by this
        date date_of_joining; //containership
        string password;      //for storing password

    private: //not inheritable information
        string airman_section_id;

    public:
        void getter()
        {
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Date of Birth:  ";
            date_of_birth.getter_date();
            cout << "Date of Joining: ";
            date_of_joining.getter_date();
        flag1:
            cout << "Set your password:\n";
            cout << "Enter new password: ";
            string pass1, pass2;
            cin >> pass1;
            cout << "Confirm new password: ";
            cin >> pass2;
            if (pass1 == pass2)
            {
                set_password(pass2);
            }
            else
            {
                cout << "\nPassword Not Matched\n";
                goto flag1;
            }
        }
        void getter_aircraftsman() //takes the information input for airman
        {
            cout << "Enter Aircraftman Id: ";
            cin >> aircraftman_id;
            getter();
            cout << "Enter Airman Section Id: ";
            cin >> airman_section_id;
        }

        void display()
        {
            cout << "\nName : " << name;
            cout << "\nDate Of Birth : ";
            date_of_birth.display_date();
            cout << "\nDate Of Joining : ";
            date_of_joining.display_date();
        }
        void display_aircraftman()
        {
            cout << "\nAircraftman Id: " << aircraftman_id;
            display();
            cout << "\nSection Id: " << airman_section_id;
        }
        void set_password(string pass)
        {
            this->password = pass;
        }
        string get_password()
        {
            return password;
        }
        string ret_air_id()
        {
            return aircraftman_id;
        }
        string ret_air_name()
        {
            return name;
        }
        int ret_aircraftman_sec_id()
        {
            if (airman_section_id == "sec1")
                return 1;
            else if (airman_section_id == "sec2")
                return 2;
            else if (airman_section_id == "sec3")
                return 3;
            else if (airman_section_id == "sec4")
                return 4;
            else if (airman_section_id == "sec5")
                return 5;
            else if (airman_section_id == "sec6")
                return 6;
            return -1;
        }
        void modify()
        {
            cout << "Enter modified Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Modified Date of Birth: ";
            date_of_birth.getter_date();
            cout << "Modified Date of Joining: ";
            date_of_joining.getter_date();
        }
        void modify_aircraftman()
        {
            modify();
            cout << "Enter modified section Id: ";
            cin >> airman_section_id;
        }
};

class flight_lieutenant : public aircraftman
{
private:
    string flight_lieu_id; //every flight lieutenent has they unique id
    string section_id; //the id of the section he is leading
public:
    void getter_flight_lieutenant()
    {
        cout << "Enter Flight Lieutenent ID: ";
        cin >> flight_lieu_id;
        aircraftman::getter();
        cout << "Enter Section ID: ";
        cin >> section_id;
    }
    void display_flight_lieutenant()
    {
        cout << "\nFlight Lieutenant Id: " << flight_lieu_id;
        aircraftman::display();
        cout << "\nSection Id: " << section_id;
    }
    string ret_fli_lieu_id()
    {
        return flight_lieu_id;
    }
    void modify_flight_lieutenant()
    {
        aircraftman::modify();
        cout << "Enter modified section Id: ";
        cin >> this->section_id;
    }
};

class squadron_leader : public flight_lieutenant //head of a squadron
{
private:
    string squadron_leader_id;
    string squadron_id;
    //string command_id;

public:
    void getter_squadron_leader()
    {
        cout << "Enter Squadron leader Id: ";
        cin >> squadron_leader_id;
        aircraftman::getter();
        cout << "Enter squadron_id(sqa1/sqa2): ";
        cin >> squadron_id;
    }
    void display_sqa_leader()
    {
        cout << "\nSquadron Leader Id: " << squadron_leader_id;
        aircraftman::display();
        cout << "\nSquadron Id: " << squadron_id;
        cout<<endl;
    }

    string ret_sqdl_id()
    {
        return squadron_leader_id;
    }
    void modify_sqd_leader()
    {
        aircraftman::modify();
        cout << "Enter modified Squadron Id: ";
        cin >> this->squadron_id;
    }
};

class section_airforce
{
protected:
    unsigned num_aircraftman; 
    string section_airforce_id;
    string flight_lieu_id;
    unsigned num_missile;
    unsigned num_fighter_jet;
    unsigned num_mp5_machine_gun;
    unsigned num_attack_helicopter;

public:
    void operator ++(int)    //operator overloading
    {
        this->num_aircraftman++ ;
    }
    void getter_section_airforce()
    {
        cout << "Enter airforce section Id: ";
        cin >> section_airforce_id;
        cout<<"Enter the number of aircraftmen: ";
        cin>>num_aircraftman;
        cout << "Enter flight lieutenant Id: ";
        cin >> flight_lieu_id;
        cout << "Enter numbers of missiles: ";
        cin >> num_missile;
        cout << "Enter number of fighter jets: ";
        cin >> num_fighter_jet;
        cout << "Enter number of machine guns: ";
        cin >> num_mp5_machine_gun;
        cout << "Enter number of attack helicopters: ";
        cin >> num_attack_helicopter;
    }
    void print_section_info()
    {
        cout<<"\nNumber of Aircraftmen: "<<num_aircraftman<<endl;
        cout << " \nFlight Lieutenant Id: " << flight_lieu_id << endl;
    } 
    //prints the weapon information
    void print_section_weapon_info()
    {
        cout << "The weapons alloted in the section are:-\n";
        cout << "No. of Missiles: " << num_missile << endl;
        cout << "No. of Fighter Jets: " << num_fighter_jet << endl;
        cout << "No. of Machine Guns: " << num_mp5_machine_gun << endl;
        cout << "No. of Attack Helicopter: " << num_attack_helicopter << endl;
    }
};

// Air Chief Marshal can access all the class using multiple inheritance.
//head of airforce    
//can view all the arsenal which airforce has    
//can edit the details of any employee
class air_chief_marshall : public squadron_leader
{
private:
    string air_chief_username;
public:
    friend class cds;
    void getter_air_chief()
    {
        cout << "Enter Air Chief Marshal Username:  ";
        cin >> air_chief_username;
        aircraftman::getter();
    }
    void display_air_chief()
    {
        cout <<"\nUsername: " << air_chief_username;
        aircraftman::display();
    }
    string ret_air_username()
    {
        return air_chief_username;
    }
    string ret_air_chief_name()
    {
        return name;
    }
};


//Class War 
//-------------

class war
{
private:
    date war_start_date;
    date war_end_date;
    string location;
    string opposition; //name of opposing country
    unsigned num_our_casualties;
    unsigned num_thiers_casualties;
    unsigned expenditure;
    string result; //one word win/loss
public:
    void getter_war()
    {
        cout << "War Beginning Date: ";
        war_start_date.getter_date();
        cout << "War End Date: ";
        war_end_date.getter_date();
        cout << "Enter the location where the war took place: ";
        cin >> location;
        cout << "Enter the name of country against which war took place: ";
        cin >> opposition;
        cout << "Enter the number of casualties from from our side: ";
        cin >> num_our_casualties;
        cout << "Enter the number of casualties from from opposing side: ";
        cin >> num_thiers_casualties;
        cout << "Enter our expenditure(in INR): ";
        cin >> expenditure;
        cout << "Enter the result(win/loss): ";
        cin >> result;
    }
    void display_war()
    {
        war_start_date.display_date();
        cout << '\t';
        war_end_date.display_date();
        cout << '\t' << opposition << '\t' << location<<"\t\t"<<num_our_casualties << "\t\t" << num_thiers_casualties << '\t' << expenditure << '\t' << result << endl;
    }
};


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//End of Class Definitions
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//functions declarations

void main_menu()
{
    char choice;
    while (true)
    {
        flag2:
        cout<<"\n\n\n\t\t ------------------------------------------------";
        cout << "\n\t\t|   DEFENCE FORCE DATABASE MANAGEMENT SYSTEM    |";
        cout<<"\n\n\t\t ------------------------------------------------\n\n";
        cout << "\tSuper Menu\n";
        cout<<"     ----------------\n";
        cout << "\n1. Army login";
        cout << "\n2. Air-Force login";
        cout << "\n3. Chief of Defence Staff(CDS) login";
        cout << "\n4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case '1':
            army_field();
            break;
        case '2':
            airforce_field();
            break;
        case '3':
            cds_field();
            break;
        case '4':
            cout<<"\nExiting the Program...";
            return;
            break;
        default:
            cout << "Error: Invalid Choice Selection\n\n";
        }
        goto flag2;
    }
}
int main()
{
    // char choice{0};
    // do
    // {
    //     add_war_details();
    //     cout<<"Enter your choice: ";
    //     cin>>choice;
    // }while(choice!= 'n');
    main_menu();
    return 0;
}

//for printing section-wise weapon info

//Army login

void army_field()
{
    flag5:
    cout << "\n\t\tArmy Menu\n";
    cout<<"\t---------------------\n\n";
    cout << "1. Login to Personal Dashboard\n";
    cout << "2. Section-wise weapon allocation\n"; ////////same as cds choice 1 for army
    cout << "3. War Details\n";
    cout << "4. Exit\n";
    cout << "9. Return to Previous Menu\n";
    cout << "\n\nEnter your choice: ";
    char choice;
    cin >> choice;
    switch (choice)
    {
    case '1':
        army_personal_dashboard();
        break;
    case '2':
    {
        ifstream fptr;
        fptr.open("army_section.bin", ios::in | ios::binary);
        if (!fptr.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        section_army sec_amy;
        int i{1};
        fptr.seekg(0 , ios::beg);
        while (fptr.read((char *)&sec_amy, sizeof(section_army)))
        {
            cout << "\nSection " << i << endl;
            cout << "------------" << endl;
            sec_amy.print_section_weapon_info();
            i++;
        }
        fptr.close();
        cin.ignore();
        cin.get();
    }
    break;
    case '3':
    {
        cout<<"\nNote: Only Army General can view and add war details\n\n";
        cout<<"Do you want to continue(y/n)? ";
        char choice;
        cin>>choice;
        if(choice=='y'||choice == 'Y')
        {
            war_details();      //general login dashboard then view history and add war
        }
        else
        {
            cout<<"\nReturning to Previous Menu...\n\n";
            goto flag5;
        }
        break;
    }
    case '4':
        cout <<"\nExiting the Program...\n";
        exit(0);
        break;
    case '9':
        main_menu();
    default:
        cout << "Error: Invalid Choice Selection"<< endl;
    }
    goto flag5;
}
void add_army_section_detail(void)
{
    ofstream fptr;
    fptr.open("army_section.bin", ios::binary|ios::app);
    if (!fptr.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    section_army s;
    s.getter_section_army();
    fptr.write((char*)&s , sizeof(section_army));
    fptr.close();
    cin.ignore();
    cin.get();
}
void add_airforce_section_detail(void)
{
    ofstream fptr;
    fptr.open("airforce_section.bin", ios::binary|ios::app);
    if (!fptr.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    section_airforce s;
    s.getter_section_airforce();
    fptr.write((char*)&s , sizeof(section_airforce));
    fptr.close();
    cin.ignore();
    cin.get();
}
void army_personal_dashboard(void)
{
    flag3:
        int ch;
        cout << "\n\n\tPersonel Dashboard Login\n";
        cout << "  ----------------------------------\n\n";
        cout << "\n1. Sepoy login";
        cout << "\n2. Lieutenant login";
        cout << "\n3. Major login";
        cout << "\n4. General login";
        cout << "\n5. Exit";
        cout << "\n9. Return to Previous menu";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
                sepoy_login();
                break;
            case 2:
                lieu_login();
                break;
            case 3:
                major_login();
                break;
            case 4:
                general_login();
            case 5:
                cout <<"\nExiting the Program...\n";
                exit(0);
            case 9:
                cout << "Going back to previous menu..." << endl;
                army_field();
                break;
            default:
                cout << "Error: Invalid Choice Selection\n\n";
        }
        goto flag3;
}

void add_user(void)     //////////////////////
{
    int choice;
    cout << "\n\t\tSELECT POST: ";
    cout << "\n1. General-Soldier:"; //sepoy
    cout << "\n2. Lieutenant";
    cout << "\n3. Major";
    cout << "\n4. General";
    cout << "\nEnter your choice: ";
    cin >> choice;
    int n;
    cout << "\nEnter the number of details: ";
    cin >> n;
    if (choice == 1)
    {
        sepoy obj;
        ofstream oFile;
        oFile.open("sepoy.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_sepoy();
            oFile.write((char *)&obj, sizeof(sepoy));
        }
        oFile.close();
        cout << "\n\nSepoy record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 2)
    {
        lieutenant obj;
        ofstream oFile;
        oFile.open("lieu.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_lieutenant();
            oFile.write((char *)&obj, sizeof(lieutenant));
        }
        oFile.close();
        cout << "\n\nlieutinant record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 3)
    {
        Major obj;
        ofstream oFile;
        oFile.open("major.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_major();
            oFile.write((char *)&obj, sizeof(Major));
        }
        oFile.close();
        cout << "\n\nmajor record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 4)
    {
        general obj;
        ofstream oFile;
        oFile.open("general.bin", ios::binary | ios::app);
        obj.getter_general();
        oFile.write((char *)&obj, sizeof(general));
        oFile.close();
        cout << "\n\nGeneral record has Been Created ";
        cin.ignore();
        cin.get();
    }
    else
        cout << "\nEnter correct choice" << endl;
}
void sepoy_login(void)
{
    cout << "\n\n\tWelcome to Sepoy login\n";
    cout << "   ----------------------------------\n\n";
    string sepoy_id;
    string password;
    cout << "\nEnter sepoy Id: ";
    cin >> sepoy_id;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file; //read mode
    file.open("sepoy.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg);
    sepoy obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(sepoy)))
    {
        if (obj.ret_sep_id() == sepoy_id && obj.get_password() == password)
        {
            found = true;
            cout <<"\nSepoy Privilages:-\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_sepoy();
                cout <<"\nEnter any key to continue to previous menu...\n\n";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)&(obj), sizeof(sepoy));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    army_field();
    cin.ignore();
    cin.get();
}

//lieutenant login
void lieu_login(void)
{
    cout << "\n\n\tWelcome to Lieutenant login\n";
    cout << "   ----------------------------------\n\n";
    string lieu_id;
    string password;
    cout << "\nEnter Lieutenant Id: ";
    cin >> lieu_id;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file; //opening in read mode
    file.open("lieu.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg); //setting the file pointer at the beginning of file
    lieutenant obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(lieutenant)))
    {
        if (obj.ret_lieu_id() == lieu_id && obj.get_password() == password)
        {
            found = true;
            cout <<"\nLieutenant Privilages:-\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_lieutenant();
                cout << "\nEnter any key to return to the previous menu...\n\n";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)(&obj), sizeof(lieutenant));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    army_field();
    cin.ignore();
    cin.get();
}
void major_login()
{
    cout << "\n\n\tWelcome to Major login\n";
    cout << "   ----------------------------------\n\n";
    string major_id;
    string password;
    cout << "\nEnter Major ID: ";
    cin >> major_id;
    cout << "\nEnter the password ";
    cin >> password;
    fstream file; //opening in read and write mode
    file.open("major.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg); //setting the file pointer at the beginning of file
    Major obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(Major)))
    {
        if (obj.ret_maj_id() == major_id && obj.get_password() == password)
        {
            found = true;
            cout <<"\nMajor Privilages:-\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "\nEnter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_major();
                cin.ignore();
                cout << "\nEnter any key to return to previous menu...\n\n";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)(&obj), sizeof(Major));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    army_field();
    cin.ignore();
    cin.get();
}


void general_login(void)
{
flag:
    cout << "\n\n\tWelcome to General login\n";
    cout << "   ----------------------------------\n\n";
    string general_usrnme;
    string password;
    cout << "\nEnter the username: ";
    cin >> general_usrnme;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file;
    file.open("general.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg);
    general obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(general)))
    {
        if (obj.ret_gene_username() == general_usrnme && obj.get_password() == password)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
    flag1:
        char choice;
        cout << "\nSelect an Operation Listed Below:-\n";
        cout << "\na. View your Profile";
        cout << "\nb. Update your Password\n";
        cout << "\n1. Add a Personel";
        cout << "\n2. Modify detail(s) of a Personel ";
        cout << "\n3. Remove a Personel";
        cout << "\n4. Exit\n";
        cout << "\n9. Return to Previous Menu\n";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 'a':
            obj.display_general();
            cin.ignore();
            cout << "\nEnter any key to continue...\n";
            cin.get();
            goto flag1;
            break;
        case 'b':
        {
            flag7:
            cout << "\nEnter your current password: ";
            string pass1;
            cin >> pass1;
            if (pass1 == obj.get_password()) //password is same variable for both sepoy and general
            {
                cout <<"\nEnter the new password: ";
                cin >> pass1;
                obj.set_password(pass1);
                int pos = (-1) * static_cast<int>(sizeof(obj));
                file.seekp(pos, ios::cur);
                file.write((char *)&(obj), sizeof(general));
                cout <<"\nPassword Changed Successfully!" << endl;
                cin.ignore();
                cout<<"\nEnter any key to continue...\n";
                cin.get();
            }
            else
            {
                cout<<"\nIncorrect Password Entered...\n";
                goto flag7;
            }
        }
            army_personal_dashboard();
            break;
        case '1':
        {
            string post_name;
            cout << "\nWhom to add(Sepoy/Lieutenant/Major): ";
            cin >> post_name;
            add_personel(post_name);
            goto flag1;
            break;
        }
        case '2':
        {
            string post_name;
            cout << "\nWhom to add(Sepoy/Lieutenant/Major): ";
            cin >> post_name;
            modify_personel(post_name);
            goto flag1;
            break;
        }
        case '3':
        {
            string post_name;
            cout << "\nWhom to add(Sepoy/Lieutenant/Major): ";
            cin >> post_name;
            delete_personel(post_name);
            goto flag1;
            break;
        }
        case '4':
            cout << "\nExiting the program..." << endl;
            exit(0);
        case '9':
            cout << "\n\n";
            army_personal_dashboard();
        default:
            cout << "Error: Invalid Choice Selection....";
            goto flag1;
            break;
        }
    }
    else
    {
        cout << "\nRecord not found in the database...";
        cout << "Do you want to try again(y/n)? ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            goto flag;
        }
        else
        {
            cout << "Exiting the program..." << endl;
            exit(0);
        }
    }
    file.close();
    cin.ignore();
    cin.get();
}
void add_personel(string post_name) //add the army personel into the section.bin and seopy.bin
{
    ofstream oFile;
    if (post_name == "Sepoy")
    {
        sepoy obj;
        oFile.open("sepoy.bin", ios::binary | ios::app);
        obj.getter_sepoy();
        oFile.write((char *)&obj, sizeof(sepoy));
        //adding that object into the section.bin file depending upon the section of the sepoy
        
        section_army sec_amy; //object to change the details in the section_army.bin file
        fstream fptr;
        fptr.open("army_section.bin", ios::binary | ios::in | ios::out);
        int secNo = obj.ret_sepoy_sec_id();
        int pos = (secNo - 1) * static_cast<int>(sizeof(sec_amy));
        fptr.seekg(pos, ios::beg);
        fptr.read((char *)&sec_amy, sizeof(section_army));
        sec_amy++;
        pos = (-1) * static_cast<int>(sizeof(sec_amy));
        fptr.seekp(pos, ios::cur);
        fptr.write((char *)&sec_amy, sizeof(section_army));
        fptr.close();
        cin.ignore();
        cin.get();
        
        cout<<"\nSepoy record has been created successfully!!\n";
    }
    else if (post_name == "Lieutenant")
    {
        lieutenant obj;
        oFile.open("lieu.bin", ios::binary | ios::app);
        obj.getter_lieutenant();
        oFile.write((char *)&obj, sizeof(lieutenant));
        cout<<"\nLieutenant record has been created successfully!!\n";
    }
    else if (post_name == "Major")
    {
        Major obj;
        oFile.open("major.bin", ios::binary | ios::app);
        obj.getter_major();
        oFile.write((char *)&obj, sizeof(Major));
        cout<<"\nMajor record has been created successfully!!\n";
    }
    else
    {
        cout <<"Error: Invalid Post-Name Inputted!!\n";
    }
    oFile.close();
    cin.ignore();
    cin.get();
    general_login();
}
void add_airforce_personel(string post_name)
{
    ofstream oFile;
    if (post_name == "Aircraftman")
    {
        aircraftman obj;
        oFile.open("aircraftman.bin", ios::binary | ios::app);
        obj.getter_aircraftsman();
        oFile.write((char *)&obj, sizeof(aircraftman));
        
        section_airforce sec_air; //object to change the details in the section_army.bin file
        fstream fptr;
        fptr.open("airforce_section.bin", ios::binary | ios::in | ios::out);
        int secNo = obj.ret_aircraftman_sec_id();
        int pos = (secNo - 1) * static_cast<int> (sizeof(sec_air));
        fptr.seekg(pos, ios::beg);
        fptr.read((char *)&sec_air, sizeof(section_airforce));
        sec_air++;
        pos = (-1) * static_cast<int>(sizeof(sec_air));
        fptr.seekg(pos, ios::cur);
        fptr.write((char *)&sec_air, sizeof(section_airforce));
        fptr.close();
        cin.ignore();
        cin.get();
        cout<<"\nAircraftman record has been created successfully!!\n";
    }
    else if (post_name == "Flight Lieutenant")
    {
        flight_lieutenant obj;
        oFile.open("flight_lieu.bin", ios::binary | ios::app);
        obj.getter_flight_lieutenant();
        oFile.write((char *)&obj, sizeof(flight_lieutenant));
        cout<<"\nFlight Lieutenant record has been created successfully!!\n";
    }
    else if (post_name == "Squadron Leader")
    {
        squadron_leader obj;
        oFile.open("squadron_leader.bin", ios::binary | ios::app);
        obj.getter_squadron_leader();
        oFile.write((char *)&obj, sizeof(squadron_leader));
        cout<<"\nSquadron Leader record has been created successfully!!\n";
    }
    else
    {
       cout <<"Error: Invalid Post-Name Inputted!!\n";
    }
    oFile.close();
    cin.ignore();
    cin.get();
    air_chief_marshal_login();
}
void modify_personel(string post_name)
{
    fstream fl;
    string id;
    cout << "\nEnter the Id:";
    cin >> id;
    bool found = false;
    if (post_name == "Sepoy")
    {
        fl.open("sepoy.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        sepoy obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(sepoy));
            if (obj.ret_sep_id() == id)
            {
                obj.modify_sepoy(); 
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(sepoy));
                section_army sec_amy; //object to change the details in the section_army.bin file
                cout << "\n\n\tRecord Updated";
                found = true;
            }
        }
    }
    else if (post_name == "Lieutenant")
    {
        fl.open("lieu.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        lieutenant obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(lieutenant));
            if (obj.ret_lieu_id() == id)
            {
                obj.modify_lieutenant(); //There is some updation required like officer does not have access to change password of user.
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(lieutenant));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else if (post_name == "Major")
    {
        fl.open("major.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        Major obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(Major));
            if (obj.ret_maj_id() == id)
            {
                obj.modify_major(); //There is some updation required like officer does not have access to change password of user.
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(Major));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else
    {
        cout << "\nInvalid Post-Name...";
        return;
    }
    fl.close();
    if (found == false)
        cout << "\n\n Record Not Found... ";
    cin.ignore();
    cin.get();
}

void modify_airforce_personel(string post_name)
{
    fstream fl;
    string id;
    cout << "\nEnter the Id:";
    cin >> id;
    bool found = false;
    if (post_name == "Aircraftman")
    {
        fl.open("aircraftman.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        aircraftman obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(aircraftman));
            if (obj.ret_air_id() == id)
            {
                obj.modify_aircraftman(); 
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(aircraftman));
                cout << "\n\n\tRecord Updated";
                found = true;
            }
        }
    }
    else if (post_name == "Flight Lieutenant")
    {
        fl.open("flight_lieu.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        flight_lieutenant obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(flight_lieutenant));
            if (obj.ret_fli_lieu_id() == id)
            {
                obj.modify_flight_lieutenant(); //There is some updation required like officer does not have access to change password of user.
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(flight_lieutenant));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else if (post_name == "Squadron Leader")
    {
        fl.open("squadron_leader.bin", ios::binary | ios::in | ios::out);
        if (!fl.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        squadron_leader obj;
        fl.seekg(0, ios::beg);
        while (!fl.eof() && found == false)
        {
            fl.read((char *)&obj, sizeof(squadron_leader));
            if (obj.ret_sqdl_id() == id)
            {
                obj.modify_sqd_leader();
                int pos = (-1) * static_cast<int>(sizeof(obj));
                fl.seekp(pos, ios::cur);
                fl.write((char *)(&obj), sizeof(squadron_leader));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
    }
    else
    {
        cout << "\nInvalid Post-Name...";
        return;
    }
    fl.close();
    if (found == false)
        cout << "\n\n Record Not Found... ";
    cin.ignore();
    cin.get();
}

void delete_personel(string post_name)
{
    string id;
    cout << "Enter the Id: ";
    cin >> id;
    ifstream iFile;
    ofstream oFile;
    oFile.open("temp.bin", ios::binary | ios::out);
    oFile.seekp(0, ios::beg);
    if (post_name == "Sepoy")
    {
        iFile.open("sepoy.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        iFile.seekg(0, ios::beg);
        sepoy obj;
        while (iFile.read((char *)(&obj), sizeof(sepoy)))
        {
            if (obj.ret_sep_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(sepoy));
            }
        }
        oFile.close();
        iFile.close();
        remove("sepoy.bin");
        rename("temp.bin", "sepoy.bin");
    }
    else if (post_name == "Lieutenant")
    {
        iFile.open("lieu.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        iFile.seekg(0, ios::beg);
        lieutenant obj;
        while (iFile.read((char *)(&obj), sizeof(lieutenant)))
        {
            if (obj.ret_lieu_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(lieutenant));
            }
        }
        oFile.close();
        iFile.close();
        remove("lieu.bin");
        rename("temp.bin", "lieu.bin");
    }
    else if (post_name == "Major")
    {
        iFile.open("major.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        iFile.seekg(0, ios::beg);
        Major obj;
        while (iFile.read((char *)(&obj), sizeof(Major)))
        {
            if (obj.ret_maj_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(Major));
            }
        }
        oFile.close();
        iFile.close();
        remove("major.bin");
        rename("temp.bin", "major.bin");
    }
    else
    {
        cout << "\nInvalid Post.....";
        return;
    }
    cout <<"\n\n\tRecord Deleted Successfully...";
    cin.ignore();
    cin.get();
}

void war_details(void)
{
    string username;
    string password;
    cout << "\nEnter Username: ";
    cin >> username;
    cout << "\nEnter Password: ";
    cin >> password;
    ifstream file;
    file.open("general.bin", ios::binary | ios::in);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg);
    general obj;
    bool found = false;
    while (!file.eof() && found == false)
    {
        file.read((char *)&obj, sizeof(general));
        if (obj.ret_gene_username() == username && obj.get_password() == password)
        {
            found = true;
            break;
        }
    }
    file.close();     //general file is closed here
    if (found)
    {
        flag:
        int choice;
        cout << "\n\nChoose the following options:- ";
        cout << "\n1. View War History";
        cout << "\n2. Add War Details";
        cout << "\n3. Exit";
        cout << "\n9. Return to Previous Menu";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            ifstream fl;
            fl.open("war.bin", ios::binary | ios::in);
            if (!fl.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            war obj;
            fl.seekg(0, ios::beg);
            cin.ignore();
            cout<<"Start_date\tEnd_date\tOpposition\tLocation No_our_casu.\tNo.their_casu.\tExpend.\tResult\n";
            while (fl.read((char *)&obj, sizeof(war)))
            {
                obj.display_war();
            }
            fl.close();
            cin.ignore();
            cin.get();
        }
        break;
        case 2:
        {
            ofstream fl;
            fl.open("war.bin", ios::binary | ios::app);
            if (!fl.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            war obj;
            int n;
            cout << "\nEnter the number of details: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                obj.getter_war();
                fl.write((char *)&obj, sizeof(war));
            }
            fl.close();
            cin.get();
            cin.ignore();
        }
        break;
        case 3:
            cout<<"\nExiting the program...";
            exit(0);
        case 9:
            army_field();
            break;
        default:
            cout<<"Error: Invalid Choice Selection\n";
            break;
        }
        goto flag;
    }
}
void war_details_airforce(void)      //air chief marshal accessses war details using this
{
    string username;
    string password;
    cout << "\nEnter Username: ";
    cin >> username;
    cout << "\nEnter Password: ";
    cin >> password;
    ifstream file;
    file.open("airchief.bin", ios::binary | ios::in);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg);
    air_chief_marshall obj;
    bool found = false;
    while (!file.eof() && found == false)
    {
        file.read((char *)&obj, sizeof(general));
        if (obj.ret_air_username() == username && obj.get_password() == password)
        {
            found = true;
            break;
        }
    }
    file.close();     //air chief marshall  file is closed here
    if (found)
    {
        flag:
        int choice;
        cout << "\n\nChoose the following options:- ";
        cout << "\n1. View War History";
        cout << "\n2. Add War Details";
        cout << "\n3. Exit";
        cout << "\n9. Return to Previous Menu";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            ifstream fl;
            fl.open("war.bin", ios::binary | ios::in);
            if (!fl.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            war obj;
            fl.seekg(0, ios::beg);
            cin.ignore();
            cout<<"Start_date\tEnd_date\tOpposition\tLocation No_our_casu.\tNo.their_casu.\tExpend.\tResult\n";
            while (fl.read((char *)&obj, sizeof(war)))
            {
                obj.display_war();
            }
            fl.close();
            cin.ignore();
            cin.get();
        }
        break;
        case 2:
        {
            ofstream fl;
            fl.open("war.bin", ios::binary | ios::app);
            if (!fl.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            war obj;
            int n;
            cout << "\nEnter the number of details: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                obj.getter_war();
                fl.write((char *)&obj, sizeof(war));
            }
            fl.close();
            cin.get();
            cin.ignore();
        }
        break;
        case 3:
            cout<<"\nExiting the program...";
            exit(0);
        case 9:
            airforce_field();
            break;
        default:
            cout<<"Error: Invalid Choice Selection\n";
            break;
        }
        goto flag;
    }
}



void delete_airforce_personel(string post_name)
{
    string id;
    cout << "Enter the Id: ";
    cin >> id;
    ifstream iFile;
    ofstream oFile;
    oFile.open("temp.bin", ios::binary | ios::out);
    oFile.seekp(0, ios::beg);
    if (post_name == "Aircraftman")
    {
        iFile.open("aircraftman.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        iFile.seekg(0, ios::beg);
        aircraftman obj;
        while (iFile.read((char *)(&obj), sizeof(aircraftman)))
        {
            if (obj.ret_air_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(aircraftman));
            }
        }
        oFile.close();
        iFile.close();
        remove("aircraftman.bin");
        rename("temp.bin", "aircraftman.bin");
    }
    else if (post_name == "Flight Lieutenant")
    {
        iFile.open("flight_lieu.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        iFile.seekg(0, ios::beg);
        flight_lieutenant obj;
        while (iFile.read((char *)(&obj), sizeof(flight_lieutenant)))
        {
            if (obj.ret_fli_lieu_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(flight_lieutenant));
            }
        }
        oFile.close();
        iFile.close();
        remove("flight_lieu.bin");
        rename("temp.bin", "flight_lieu.bin");
    }
    else if (post_name == "squadron_leader")
    {
        iFile.open("squadron_leader.bin", ios::binary | ios::in);
        if (!iFile.is_open())
        {
            cout << "Error: File couldn't be opened...";
            cout << "Exiting the program...";
            exit(0);
        }
        iFile.seekg(0, ios::beg);
        squadron_leader obj;
        while (iFile.read((char *)(&obj), sizeof(squadron_leader)))
        {
            if (obj.ret_sqdl_id() != id)
            {
                oFile.write((char *)(&obj), sizeof(squadron_leader));
            }
        }
        oFile.close();
        iFile.close();
        remove("squadron_leader.bin");
        rename("temp.bin", "squadron_leader.bin");
    }
    else
    {
        cout << "\nInvalid Post.....";
        return;
    }
    cout <<"\n\n\tRecord Deleted Successfully...";
    cin.ignore();
    cin.get();
}

void airforce_field()
{
    flag5:
    cout <<"\n\t\tAir Force Menu\n";
    cout<<"\t-----------------------\n\n";
    cout << "1. Login to Personal Dashboard\n";
    cout << "2. Section-wise weapon allocation\n";
    cout << "3. War Details\n";
    cout << "4. Exit\n";
    cout << "9. Return to Previous Menu\n";
    cout << "\n\nEnter your choice: ";
    char choice;
    cin >> choice;
    switch (choice)
    {
    case '1':
        air_personal_dashboard();
        break;
    case '2':
        {
            ifstream fptr;
            fptr.open("airforce_section.bin", ios::in | ios::binary);
            if (!fptr.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            section_airforce sec_air;
            int i{1};
            fptr.seekg(0 , ios::beg);
            while (fptr.read((char *)&sec_air, sizeof(section_airforce)))
            {
                cout << "Section " << i << endl;
                cout << "------------" << endl;
                sec_air.print_section_weapon_info();
                i++;
            }
            fptr.close();
            cin.ignore();
            cin.get();
    }
    break;
    case '3':
    {
        cout<<"\nNote: Only Air Chief Marshal can view and add war details\n\n";
        cout<<"Do you want to continue(y/n)? ";
        char choice;
        cin>>choice;
        if(choice=='y'||choice == 'Y')
        {
            war_details_airforce();      //air chief login dashboard then view history and add war
        }
        else
        {
            cout<<"\nReturning to Previous Menu...\n\n";
            goto flag5;
        }
        break;
    }
    case '4':
        cout <<"\nExiting the Program...\n";
        exit(0);
        break;
    case '9':
        main_menu();
    default:
        cout << "Error: Invalid Choice Selection"<< endl;
    }
    goto flag5;
}

void air_personal_dashboard(void)
{
    flag3:
        char ch;
        cout << "\n\n\tPersonel Dashboard Login\n";
        cout << "  ----------------------------------\n\n";
        cout << "\n1. Aircraftman login";
        cout << "\n2. Flight Lieutenant login";
        cout << "\n3. Squadron Leader login";
        cout << "\n4. Airforce Cheif Marshal login";
        cout << "\n5. Exit";
        cout << "\n9. Return to Previous menu";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
            case '1':
                aircraftman_login();
                break;
            case '2':
                flight_lieu_login();
                break;
            case '3':
                squad_leader_login();
                break;
            case '4':
                air_chief_marshal_login();
            case '5':
                cout <<"\nExiting the Program...\n";
                exit(0);
            case '9':
                cout << "Going back to previous menu..." << endl;
                airforce_field();
                break;
            default:
                cout << "Error: Invalid Choice Selection\n\n";
        }
        goto flag3;
}

void add_airforce_user(void) ////////////////////
{
    int choice;
    cout << "\n\t\tSELECT POST: ";
    cout << "\n1. Aircraftman:";
    cout << "\n2. Flight Lieutenant";
    cout << "\n3. Squadron Leader";
    cout << "\n4. Air Chief Marshall";
    cout << "\nEnter your choice: ";
    cin >> choice;
    int n;
    cout << "\nEnter the number of details: ";
    cin >> n;
    if (choice == 1)
    {
        aircraftman obj;
        ofstream oFile;
        oFile.open("aircraftman.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_aircraftsman();
            oFile.write((char *)&obj, sizeof(aircraftman));
        }
        oFile.close();
        cout << "\n\nAircraftman record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 2)
    {
        flight_lieutenant obj;
        ofstream oFile;
        oFile.open("flight_lieu.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_flight_lieutenant();
            oFile.write((char *)&obj, sizeof(flight_lieutenant));
        }
        oFile.close();
        cout << "\n\nflight lieutinant record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 3)
    {
        squadron_leader obj;
        ofstream oFile;
        oFile.open("squadron_leader.bin", ios::binary | ios::app);
        for (int i = 0; i < n; i++)
        {
            obj.getter_squadron_leader();
            oFile.write((char *)&obj, sizeof(squadron_leader));
        }
        oFile.close();
        cout << "\nSquadron Leader record Has Been Created ";
        cin.ignore();
        cin.get();
    }
    else if (choice == 4)
    {
        air_chief_marshall obj;
        ofstream oFile;
        oFile.open("airchief.bin", ios::binary | ios::app);
        obj.getter_air_chief();
        oFile.write((char *)&obj, sizeof(air_chief_marshall));
        oFile.close();
        cout << "\nAir Cheif Marshal record has Been Created\n ";
        cin.ignore();
        cin.get();
    }
    else
        cout << "\nEnter correct choice" << endl;
}

void aircraftman_login(void)
{
    cout << "\n\n\tWelcome to Aircraftman login\n";
    cout << "   ----------------------------------------\n\n";
    string aircraftman_id;
    string password;
    cout << "\nEnter aircraftman Id: ";
    cin >> aircraftman_id;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file; //read mode
    file.open("aircraftman.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg);
    aircraftman obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(aircraftman)))
    {
        if (obj.ret_air_id() == aircraftman_id && obj.get_password() == password)
        {
            found = true;
            cout <<"\nAircraftman Privilages:-\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_aircraftman();
                cin.ignore();
                cout <<"\nEnter any key to continue to previous menu...\n\n";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)&(obj), sizeof(aircraftman));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    airforce_field();
    cin.ignore();
    cin.get();
}

void flight_lieu_login()
{
    cout << "\n\n\tWelcome to Flight Lieutenant login\n";
    cout << "   ----------------------------------------\n\n";
    string flight_lieu_id;
    string password;
    cout << "\nEnter Flight Lieutenant Id: ";
    cin >> flight_lieu_id;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file; //opening in read mode
    file.open("flight_lieu.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg); //setting the file pointer at the beginning of file
    flight_lieutenant obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(flight_lieutenant)))
    {
        if (obj.ret_fli_lieu_id() == flight_lieu_id && obj.get_password() == password)
        {
            found = true;
            cout <<"\nFlight Lieutenant Privilages:-\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_flight_lieutenant();
                cout << "\nEnter any key to return to the previous menu...\n\n";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)(&obj), sizeof(flight_lieutenant));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    airforce_field();
    cin.ignore();
    cin.get();
}

void squad_leader_login()
{
    cout << "\n\n\tWelcome to Squadron Leader login\n";
    cout << "   ---------------------------------------------\n\n";
    string squadron_leader_id;
    string password;
    cout << "\nEnter Squadron Leader ID: ";
    cin >> squadron_leader_id;
    cout << "\nEnter the password ";
    cin >> password;
    fstream file; //opening in read and write mode
    file.open("squadron_leader.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg); //setting the file pointer at the beginning of file
    squadron_leader obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(squadron_leader)))
    {
        if (obj.ret_sqdl_id() == squadron_leader_id && obj.get_password() == password)
        {
            found = true;
            cout <<"\nSquadron Leader Privilages:-\n";
            cout << "1. View your Profile\n";
            cout << "2. Change your password\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                obj.display_sqa_leader();
                cout << "\nEnter any key to return to previous menu...\n\n";
                cin.get();
            }
            else if (choice == 2)
            {
                cout << "Enter your current password: ";
                string pass1;
                cin >> pass1;
                if (pass1 == obj.get_password())
                {
                    cout << "Enter the new password: ";
                    cin >> pass1;
                    obj.set_password(pass1);
                    int pos = (-1) * static_cast<int>(sizeof(obj));
                    file.seekp(pos, ios::cur);
                    file.write((char *)(&obj), sizeof(squadron_leader));
                    cout << "\nPassword Changed Successfully!" << endl;
                }
            }
            break;
        }
    }
    if (!found)
    {
        cout << "Incorrect Password or Record not found in database\n";
    }
    file.close();
    airforce_field();
    cin.ignore();
    cin.get();
}

void air_chief_marshal_login(void)
{
flag:
    cout << "\n\n\tWelcome to Air Chief Marshal login\n";
    cout << "   ----------------------------------\n\n";
    string air_cheif_usrnme;
    string password;
    cout << "\nEnter the username: ";
    cin >> air_cheif_usrnme;
    cout << "\nEnter the Password: ";
    cin >> password;
    fstream file;
    file.open("airchief.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    file.seekg(0, ios::beg);
    air_chief_marshall obj;
    bool found = false;
    while (file.read((char *)&obj, sizeof(air_chief_marshall)))
    {
        if (obj.ret_air_username() == air_cheif_usrnme && obj.get_password() == password)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
    flag1:
        char choice;
        cout << "\nSelect an Operation Listed Below:-\n";
        cout << "\na. View your Profile";
        cout << "\nb. Update your Password\n";
        cout << "\n1. Add a Personel";
        cout << "\n2. Modify detail(s) of a Personel";
        cout << "\n3. Remove a Personel: ";
        cout << "\n4. Exit\n";
        cout << "\n9. Return to Previous Menu\n";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 'a':
            obj.display_air_chief();
            cin.ignore();
            cout << "\nEnter any key to continue...\n";
            cin.get();
            goto flag1;
            break;
        case 'b':
        {
            flag7:
            cout << "\nEnter your current password: ";
            string pass1;
            cin >> pass1;
            if (pass1 == obj.get_password()) //password is same variable for both sepoy and general
            {
                cout << "Enter the new password: ";
                cin >> pass1;
                obj.set_password(pass1);
                int pos = (-1) * static_cast<int>(sizeof(obj));
                file.seekp(pos, ios::cur);
                file.write((char *)&(obj), sizeof(air_chief_marshall));
                cout <<"\nPassword Changed Successfully!" << endl;
                cin.ignore();
                cout<<"\nEnter any key to continue...\n";
                cin.get();
            }
            else 
            {
                cout<<"\nIncorrect Password Entered...\n";
                goto flag7;
            }
        }
            air_personal_dashboard();
            break;
        case '1':
        {
            string post_name;
            cout << "\nWhom to add(Aircraftman/Flight Lieutenant/Squadron Leader): ";
            cin >> post_name;
            add_airforce_personel(post_name);
            goto flag1;
            break;
        }
        case '2':
        {
            string post_name;
            cout << "\nWhom to modify(Aircraftman/Flight Lieutenant/Squadron Leader): ";
            cin >> post_name;
            modify_airforce_personel(post_name);
            goto flag1;
            break;
        }
        case '3':
        {
            string post_name;
            cout << "\nWhom to remove(Aircraftman/Flight Lieutenant/Squadron Leader): ";
            cin >> post_name;
            delete_airforce_personel(post_name);
            goto flag1;
            break;
        }
        case '4':
            cout << "\nExiting the program..." << endl;
            exit(0);
        case '9':
            cout << "\n\n";
            air_personal_dashboard();
        default:
            cout << "Error: Invalid Choice Selection....";
            goto flag1;
            break;
        }
    }
    else
    {
        cout << "\nRecord not found in the database...";
        cout << "Do you want to try again(y/n)? ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            goto flag;
        }
        else
        {
            cout << "Exiting the program..." << endl;
            exit(0);
        }
    }
    file.close();
    cin.ignore();
    cin.get();
}


void cds_field(void)
{
    cds_login();
}
void cds_login(void)
{
    cout<<"\n\n\tCheif Defence of Staff\n";
    cout<<"    ---------------------------\n\n";
    string username;
    string password;
    cout << "\nEnter Username: ";
    cin >> username;
    cout << "\nEnter Password: ";
    cin >> password;
    fstream file;
    file.open("cds.bin", ios::binary | ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    bool found = false;
    cds obj;
    file.seekg(0, ios::beg);
    while (!file.eof() && found == false)
    {
        file.read((char *)&obj, sizeof(cds));
        if (obj.ret_username_cds() == username && obj.ret_password_cds() == password)
        {
            found = true;
            cout<<"\nYour Profile:-\n";
            obj.display_cds();
            break;
        }
    }
    if (found)
    {
        flag:
        int ch;
        cout<<"\n\tCDS Previlages\n";
        cout<<"   --------------------\n";
        cout << "\n1. Password Change ";
        cout << "\n2. Army Details";
        cout << "\n3. Airforce Details";
        cout << "\n4. War Details";
        cout<<"\n5. Logout";
        cout<<"\n6. Exit";
        cout << "\n\nEnter your Choice ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter your current password: ";
            string pass1;
            cin >> pass1;
            if (pass1 == obj.ret_password_cds())
            {
                cout << "Enter the new password: ";
                cin >> pass1;
                // change_pass_sepoy(obj.ret_sep_id(), pass1, "Sepoy");
                obj.set_password_cds(pass1);
                int pos = (-1) * static_cast<int>(sizeof(obj));
                file.seekp(pos, ios::cur);
                file.write((char *)&(obj), sizeof(cds));
                cout << "\nPassword Changed Successfully!" << endl;
            }
            break;
        }
        case 2:
        {
            int choice;
            cout << "\n1. Weapon Details: ";
            cout << "\n2. Sepoy Details: ";
            cout << "\n3. Lieutenant Details:";
            cout << "\n4. Major Details: ";
            cout << "\n5. General Details: ";
            cout << "\nEnter the choice: ";
            cin >> choice;
            if (choice == 1)
            {
                ifstream fptr;
                fptr.open("army_section.bin", ios::in | ios::binary);
                if (!fptr.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                section_army sec_amy;
                int i{1};
                fptr.seekg(0 , ios::beg);
                while (fptr.read((char *)&sec_amy, sizeof(section_army)))
                {
                    cout << "Section " << i << endl;
                    cout << "------------" << endl;
                    sec_amy.print_section_weapon_info();
                    i++;
                }
                fptr.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 2)
            {
                ifstream fl;
                fl.open("sepoy.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                sepoy s;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&s, sizeof(sepoy)))
                {
                    s.display_sepoy();
                    cout << endl
                         << endl;
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 3)
            {
                ifstream fl;
                fl.open("lieu.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                lieutenant l;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&l, sizeof(lieutenant)))
                {
                    l.display_lieutenant();
                    cout << endl
                         << endl;
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 4)
            {
                ifstream fl;
                fl.open("major.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                Major m;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&m, sizeof(Major)))
                {
                    m.display_major();
                    cout << endl
                         << endl;
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 5)
            {
                ifstream fl;
                fl.open("general.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                general g;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&g, sizeof(general)))
                {
                    g.display_general();
                    cout << endl
                         << endl;
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else
            {
                cout << "\nInvalid Operation.....";
            }
            goto flag;
            break;
        }
        case 3:
        {
            int choice;
            cout <<" CDS Air Force Privilages:-\n";
            cout << "\n1. Weapon Details ";
            cout << "\n2. Aircraftman Details";
            cout << "\n3. Flight Lieu Details";
            cout << "\n4. Squadraon Leader Details";
            cout << "\n5. Chief Air Marshall Details";
            cout << "\nEnter your choice: ";
            cin >> choice;
            if (choice == 1)
            {
                ifstream fptr;
                fptr.open("airforce_section.bin", ios::in | ios::binary);
                if (!fptr.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                section_airforce sec_air;
                int i{1};
                fptr.seekg(0 , ios::beg);
                while (fptr.read((char *)&sec_air, sizeof(section_airforce)))
                {
                    cout << "\nSection " << i << endl;
                    cout << "------------" << endl;
                    sec_air.print_section_weapon_info();
                    i++;
                }
                fptr.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 2)
            {
                ifstream fl;
                fl.open("aircraftman.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                aircraftman s;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&s, sizeof(aircraftman)))
                {
                    s.display_aircraftman();
                    cout << "\n\n";
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 3)
            {
                ifstream fl;
                fl.open("flight_lieu.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                flight_lieutenant s;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&s, sizeof(flight_lieutenant)))
                {
                    s.display_flight_lieutenant();
                    cout << "\n\n";
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 4)
            {
                ifstream fl;
                fl.open("squadron_leader.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                squadron_leader s;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&s, sizeof(squadron_leader)))
                {
                    s.display_sqa_leader();
                    cout << "\n\n";
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            else if (choice == 5)
            {
                ifstream fl;
                fl.open("airchief.bin", ios::binary | ios::in);
                if (!fl.is_open())
                {
                    cout << "Error: File couldn't be opened...";
                    cout << "Exiting the program...";
                    exit(0);
                }
                air_chief_marshall s;
                fl.seekg(0, ios::beg);
                while (fl.read((char *)&s, sizeof(air_chief_marshall)))
                {
                    s.display_air_chief();
                    cout << "\n\n";
                }
                fl.close();
                cin.ignore();
                cin.get();
            }
            goto flag;
            break;
        }
        case 4:
        {
            ifstream fl;
            fl.open("war.bin", ios::binary | ios::in);
            if (!fl.is_open())
            {
                cout << "Error: File couldn't be opened...";
                cout << "Exiting the program...";
                exit(0);
            }
            war w;
            fl.seekg(0, ios::beg);
            cout<<"Start_date\tEnd_date\tOpposition\tLocation\tNo_our_casu.\tNo.their_casu.\tExpend.\tResult\n";
            while (fl.read((char *)&w, sizeof(war)))
            {
                w.display_war();
            }
            fl.close();
            cin.ignore();
            cin.get();
        }
        goto flag;
        break;
        case 5:
            cout<<"\nLogging Out...\n";
            return;
        case 6:
            cout<<"\nExiting the program...\n";
            exit(0);
        default:
            cin.ignore();
            cout << "\nError: Invalid Choice Selection...";
            cout<<"\nEnter any key to continue...\n";
            cin.get();
            goto flag;
        }
    }
    else
        cout << "\nRecord not Found...\n";
    file.close();
    cin.ignore();
    cin.get();
}









/*void add_sepoy_to_section_(sepoy &s) 
{
    ofstream file;
    file.open("section.bin", ios::binary | ios::app);
    if (!file.is_open())
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get(); //////////handle here correctly
        return;
    }
    section_army obj;
    obj.getter_section_army(s);
    int n;
    for (int i = 0; i < n; i++)
    {
        ifstream fl;
        fl.open("sepoy.bin", ios::binary | ios::in);
        if (!fl.is_open())
        {
            cout << "File could not be opened !! Press any Key to exit";
            cin.ignore();
            cin.get(); //////////handle here correctly
            return;
        }
        obj.getter_section_army(s);
        file.write((char *)&obj, sizeof(section_army));
    }
    file.close();
    cin.ignore();
    cin.get();
}*/






// // class company
// // {
// // private:
// //     //vector<section_army> sec; //has the list of sections -> section id , lietinant_id, lietunant name
// //     string company_id;
// //     string major_id;

// // public:
// //     //unsigned num_section();
// //     //void getter_company(); //this is a temporary function just to enter initial values
// //     //void print_company_info()
// //     //{
// //         // cout << "Company Id: " << company_id << endl;
// //         // cout << "The sections in this company are:-\n";
// //         // for (int i = 0; i < sec.size() - 1; i++)
// //         // {
// //         //     sec.at(i).print_section_info();
// //         //     cout << endl
// //         //          << endl;
// //         // }
// //         // cout << " \nMajor Id: " << major_id << endl;
// //     //}
// // };

//will changes in the sepoy reflect in the platoon binary file implicitly or do we have to handle it explicitly
// class platoon
// {
// private:
//     vector<company> com;
//     //instead of platoon id to be string i was thinking of it as unsigned
//     string platoon_id;
//     string lieutinant_gen_id;

// public:
//     //unsigned num_companies();
//     void getter_platoon();
//     //temporary input function required
//     void print_platoon_info() const;
// };



// class squadron //which sections are in which company/platoon is hardcoded.
// {
// private:
//     vector<section_airforce> sec; //has the list of sections -> section id , lietinant_id, lietunant name
//     string squadron_id;
//     string squadron_leader_id;
//     // string weapon_id;    //it may be removed
// public:
//     // unsigned num_section();
//     void print_squadron_info()
//     {
//         cout << "Squadron ID" << squadron_id << endl;
//         cout << "The Sections in this Squadron are:-\n";
//         for (int i = 0; i < sec.size() - 1; i++)
//         {
//             sec.at(i).print_section_info();
//             cout << endl
//                  << endl;
//         }
//         cout << "Squadron Leader ID: " << squadron_leader_id << endl;
//     };
//     void get_squadron_info();
//     // void print_weapon_info();
// };
// class command
// {
// private:
//     vector<squadron> com;
//     //instead of platoon id to be string i was thinking of it as unsigned
//     string command_id;
//     string marshall_id;
//     // string weapon_id;
// public:
//     // unsigned num_squadron();
//     void print_command_info() const;
//     void get_command_info();
//     // void print_weapon_info();
// };



//function that General can do
    //edit or modify details of any soldier
    //add and remove any soldier
    //view all the arsenal data which army has
    //can view/modify and delete all the info related to war and conflicts
    //add functions accordingly

        //function that Air Cheif Marshal can do
    //edit or modify details of any soldier
    //add and remove any soldier
    //view all the arsenal data which army has
    //can view/modify and delete all the info related to war and conflicts
    //add functions accordingly



    // void change_pass_sepoy(string id, string password)
// {
//     bool found = false;
//     sepoy obj;
//     fstream fl;
//     fl.open("sepoy.bin", ios::binary | ios::in | ios::out);
//     if (!fl.is_open())
//     {
//         cout << "File could not be opened. Press any Key to exit...";
//         cin.ignore();
//         cin.get();
//         return; /////////////////handle here correctly
//     }
//     fl.seekg(0, ios::beg);
//     while (!fl.eof() && found == false)
//     {
//         fl.read((char *)(&obj), sizeof(sepoy));
//         if (obj.ret_sep_id() == id)
//         {
//             obj.set_password(password);
//             int pos = (-1) * static_cast<int>(sizeof(obj));
//             fl.seekp(pos, ios::cur);
//             fl.write((char *)(&obj), sizeof(sepoy));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }
//     fl.close();
//     if (found == false)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }

    // if (found)
    // {
    //     string new_password;
    //     cout << "\nWant to change password: ";
    //     char ch;
    //     cin>>ch;
    //     cin >> new_password;
    //     change_pass(sepoy_id, new_password);
    // }
    // else
    // cout << "\nRecords not found!!";


    // if (found)
    // {
    //     string new_password;
    //     cout << "\nWant to change password: ";
    //     char ch;
    //     cin>>ch;
    //     cin >> new_password;
    //     change_pass(sepoy_id, new_password);
    // }
    // else
    // cout << "\nRecords not found!!";

    // void change_passwd_general(string usrnme, string password)
// {
//     bool found = false;
//     general obj;
//     fstream fl;
//     fl.open("general.bin", ios::binary | ios::in | ios::out);
//     if (!fl.is_open())
//     {
//         cout << "General Information could not be fetched\n";
//         cout << "Error: File could not be opened.\n";
//         cout << "Press any Key to exit..."; //////
//         cin.ignore();
//         cin.get();
//         return;
//     }
//     fl.seekg(0, ios::beg);
//     while (!fl.eof() && found == false)
//     {
//         fl.read((char *)(&obj), sizeof(general));
//         if (obj.ret_gene_username() == usrnme)
//         {
//             obj.set_password(password);
//             int pos = (-1) * static_cast<int>(sizeof(obj));
//             fl.seekp(pos, ios::cur);
//             fl.write((char *)(&obj), sizeof(general));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }
//     fl.close();
//     if (found == false)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }



// void delete_airforce_personel(string post_name)
// {
//     string id;
//     cout << "Enter the Id: ";
//     cin >> id;
//     ifstream iFile;
//     ofstream oFile;
//     oFile.open("temp.bin", ios::binary | ios::out);
//     oFile.seekp(0, ios::beg);
//     if (post_name == "Sepoy")
//     {
//         iFile.open("sepoy.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         sepoy obj;
//         while (iFile.read((char *)(&obj), sizeof(sepoy)))
//         {
//             if (obj.ret_sep_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(sepoy));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("sepoy.bin");
//         rename("temp.bin", "sepoy.bin");
//     }
//     else if (post_name == "Lieutenant")
//     {
//         iFile.open("lieu.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         lieutenant obj;
//         while (iFile.read((char *)(&obj), sizeof(lieutenant)))
//         {
//             if (obj.ret_lieu_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(lieutenant));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("lieu.bin");
//         rename("temp.bin", "lieu.bin");
//     }
//     else if (post_name == "Major")
//     {
//         iFile.open("major.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         Major obj;
//         while (iFile.read((char *)(&obj), sizeof(Major)))
//         {
//             if (obj.ret_maj_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(Major));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("major.bin");
//         rename("temp.bin", "major.bin");
//     }
//     else
//     {
//         cout << "\nInvalid Post.....";
//         return;
//     }
//     cout << "\n\n\tRecord Deleted ..";
//     cin.ignore();
//     cin.get();
// }

// void delete_personel(string post_name)
// {
//     string id;
//     cout << "Enter the Id: ";
//     cin >> id;
//     ifstream iFile;
//     ofstream oFile;
//     oFile.open("temp.bin", ios::binary | ios::out);
//     oFile.seekp(0, ios::beg);
//     if (post_name == "Sepoy")
//     {
//         iFile.open("sepoy.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         sepoy obj;
//         while (iFile.read((char *)(&obj), sizeof(sepoy)))
//         {
//             if (obj.ret_sep_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(sepoy));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("sepoy.bin");
//         rename("temp.bin", "sepoy.bin");
//     }
//     else if (post_name == "Lieutenant")
//     {
//         iFile.open("lieu.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         lieutenant obj;
//         while (iFile.read((char *)(&obj), sizeof(lieutenant)))
//         {
//             if (obj.ret_lieu_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(lieutenant));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("lieu.bin");
//         rename("temp.bin", "lieu.bin");
//     }
//     else if (post_name == "Major")
//     {
//         iFile.open("major.bin", ios::binary | ios::in);
//         if (!iFile.is_open())
//         {
//             cout << "File could not be opened... Press any Key to exit...";
//             cin.ignore();
//             cin.get();
//             return;
//         }
//         iFile.seekg(0, ios::beg);
//         Major obj;
//         while (iFile.read((char *)(&obj), sizeof(Major)))
//         {
//             if (obj.ret_maj_id() != id)
//             {
//                 oFile.write((char *)(&obj), sizeof(Major));
//             }
//         }
//         oFile.close();
//         iFile.close();
//         remove("major.bin");
//         rename("temp.bin", "major.bin");
//     }
//     else
//     {
//         cout << "\nInvalid Post.....";
//         return;
//     }
//     cout << "\n\n\tRecord Deleted ..";
//     cin.ignore();
//     cin.get();
// }



// {
//     ofstream fl;
//     fl.open("war.bin", ios::binary | ios::app);
//     if (!fl.is_open())
//     {
//         cout << "File could not be opened... Press any Key to exit...";
//         cin.ignore();
//         cin.get();
//         return;
//     }
//     war obj;
//     obj.getter_war();
//     fl.write((char *)&obj, sizeof(war));
//     fl.close();
//     cin.ignore();
//     cin.get();
// }
// break;
// default:
// cout << "\nEnter correct choice...";
// break;
// }
// }
// }


// void change_pass_sepoy(string id, string password)
// {
//     bool found = false;
//     sepoy obj;
//     fstream fl;
//     fl.open("sepoy.bin", ios::binary | ios::in | ios::out);
//     if (!fl.is_open())
//     {
//         cout << "File could not be opened. Press any Key to exit...";
//         cin.ignore();
//         cin.get();
//         return; /////////////////handle here correctly
//     }
//     fl.seekg(0, ios::beg);
//     while (!fl.eof() && found == false)
//     {
//         fl.read((char *)(&obj), sizeof(sepoy));
//         if (obj.ret_sep_id() == id)
//         {
//             obj.set_password(password);
//             int pos = (-1) * static_cast<int>(sizeof(obj));
//             fl.seekp(pos, ios::cur);
//             fl.write((char *)(&obj), sizeof(sepoy));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }
//     fl.close();
//     if (found == false)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }


// void change_passwd_general(string usrnme, string password)
// {
//     bool found = false;
//     general obj;
//     fstream fl;
//     fl.open("general.bin", ios::binary | ios::in | ios::out);
//     if (!fl.is_open())
//     {
//         cout << "General Information could not be fetched\n";
//         cout << "Error: File could not be opened.\n";
//         cout << "Press any Key to exit..."; //////
//         cin.ignore();
//         cin.get();
//         return;
//     }
//     fl.seekg(0, ios::beg);
//     while (!fl.eof() && found == false)
//     {
//         fl.read((char *)(&obj), sizeof(general));
//         if (obj.ret_gene_username() == usrnme)
//         {
//             obj.set_password(password);
//             int pos = (-1) * static_cast<int>(sizeof(obj));
//             fl.seekp(pos, ios::cur);
//             fl.write((char *)(&obj), sizeof(general));
//             cout << "\n\n\t Record Updated";
//             found = true;
//         }
//     }
//     fl.close();
//     if (found == false)
//         cout << "\n\n Record Not Found ";
//     cin.ignore();
//     cin.get();
// }

//adds the cds details into the file
// void add_cds_details(void)
// {
//     ofstream file;
//     file.open("cds.bin", ios::binary | ios::app);
//     if (!file.is_open())
//     {
//         cout << "Error: File couldn't be opened...";
//         cout << "Exiting the program...";
//         exit(0);
//     }
//     cds obj;
//     obj.getter_cds();
//     file.write((char *)&obj, sizeof(cds));
//     cout << "\nImfomation stored successfully...";
//     file.close();
//     cin.ignore();
//     cin.get();
// }


void add_war_details(void)   ///////////It is temporary
{
    ofstream file;
    file.open("war.bin", ios::binary | ios::app);
    if (!file.is_open())
    {
        cout << "Error: File couldn't be opened...";
        cout << "Exiting the program...";
        exit(0);
    }
    int n;
    war obj;
    cout << "\nHow many Details you want to enter: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        obj.getter_war();
        file.write((char *)&obj, sizeof(war));
    }
    file.close();
    cin.ignore();
    cin.get();
}


