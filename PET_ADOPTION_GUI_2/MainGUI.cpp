#include "PetAdopterWindow.h"
#include "pet_seller_window.h"
#include "petsellerprofilewindow.h"
#include "petadopterprofilewindow.h"
#include "petinfowindow.h"
#include "postpagewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Create instances of both windows
    PetAdopterWindow PetAdopterLoginWindow; //this is actually for PetADopterWindow.h the login window
    PetSellerWindow PetSellerLoginWindow;
    PetSellerProfileWindow PetSellerProfileWindow;
    PetAdopterProfileWindow PetAdopterProfileWindow;
    PetInfoWindow PetInfoLoginWindow;
    PostPageWindow PostsHomePage1;
    PostPageWindow PostsHomePage2;

    // Show both windows
    PostsHomePage1.show();
    PetAdopterProfileWindow.show();
    PetAdopterLoginWindow.show();

    PostsHomePage2.show();
    PetSellerProfileWindow.show();
    PetInfoLoginWindow.show();
    PetSellerLoginWindow.show();
    return a.exec();
}
