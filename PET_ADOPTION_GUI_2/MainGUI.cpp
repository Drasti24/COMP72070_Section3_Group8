#include "PetAdopterWindow.h"
#include "pet_seller_window.h"
#include "petsellerprofilewindow.h"
#include "petadopterprofilewindow.h"
#include "petinfowindow.h"
#include "postpagewindow.h"
#include "commonloginwindow.h"
#include "welcomewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Create instances of both windows
    PetAdopterWindow PetAdopterSignUpWindow; //this is actually for PetADopterWindow.h the sign up window
    PetSellerWindow PetSellerSignUpWindow;
    PetSellerProfileWindow PetSellerProfileWindow;
    PetAdopterProfileWindow PetAdopterProfileWindow;
    PetInfoWindow PetInfoSignUpWindow;
    PostPageWindow PostsHomePage1;
    PostPageWindow PostsHomePage2;
    CommonLoginWindow LogIn;
    WelcomeWindow welcome;

    // Show both windows
    PostsHomePage1.show();
    PetAdopterProfileWindow.show();
    PetAdopterSignUpWindow.show();

    PostsHomePage2.show();
    PetSellerProfileWindow.show();
    PetInfoSignUpWindow.show();
    PetSellerSignUpWindow.show();
    LogIn.show();
    welcome.show();

    return a.exec();
}
