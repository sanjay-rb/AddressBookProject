#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include "qtcontactform.h"



QtContactForm::QtContactForm(QWidget *parent) : 
        QFormLayout(parent), firstNameField(new QLineEdit()),
        lastNameField(new QLineEdit()),
        addressField(new QLineEdit()),
        phoneNumberField(new QLineEdit()),
        emailField(new QLineEdit()),
        cityField(new QLineEdit()),
        ageField(new QLineEdit())

{
    addRow("<font color='red'>First Name</font>", firstNameField);
    addRow("Last Name", lastNameField);
    addRow("Address", addressField);
    addRow("Phone Number", phoneNumberField);
    addRow("Email", emailField);
    addRow("City", cityField);
    addRow("Age", ageField);

}

void QtContactForm::clear()
{
    firstNameField->setText("");
    lastNameField->setText("");
    addressField->setText("");
    phoneNumberField->setText("");
    emailField->setText("");
    cityField->setText("");
    ageField->setText("");


}
