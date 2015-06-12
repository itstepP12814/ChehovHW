using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NoteBookLib
{
    public class Note
    {
        public Note() { }
        public Note(string fName, string lName, string bDay, string mail, string tel)
        {
            firstName = fName;
            lastName = lName;
            birthDay = bDay;
            eMail = mail;
            telNumber = tel;
        }
        public string FirstName
        {
            get { return firstName; }
            set { FirstName = value; }
        }
        public string LastName
        {
            get { return lastName; }
            set { lastName = value; }
        }
        public string BirthDay
        {
            get { return birthDay; }
            set { birthDay = value; }
        }
        public string Email
        {
            get { return eMail; }
            set { eMail = value; }
        }
        public string TelNumber
        {
            get { return telNumber; }
            set { telNumber = value; }
        }
        public override string ToString()
        {
            return String.Format(lastName + " " + firstName + " " + birthDay + " " + eMail + " " + telNumber);
        }
        private string firstName;
        private string lastName;
        private string birthDay;
        private string eMail;
        private string telNumber;
    }
}
