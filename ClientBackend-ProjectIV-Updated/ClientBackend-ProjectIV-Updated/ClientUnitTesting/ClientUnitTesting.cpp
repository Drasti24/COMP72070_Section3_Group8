#include "pch.h"
#include "CppUnitTest.h"
#include"..\ClientBackend-ProjectIV\Login.h"
#include"..\ClientBackend-ProjectIV\PetAdopter.h"
#include"..\ClientBackend-ProjectIV\PetSeller.h"
#include"..\ClientBackend-ProjectIV\ProvinceEnum.h"
#include"..\ClientBackend-ProjectIV\UserProfile.h"
#include"..\ClientBackend-ProjectIV\Packet.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace PetAdoption;
namespace ClientUnitTesting
{
	TEST_CLASS(ClientUnitTesting)
	{
	public:
		
		TEST_METHOD(TestDefaultConstructor)
		{
			Login login;
			Assert::AreEqual(std::string(""), login.getUsername());
			Assert::AreEqual(std::string(""), login.getPassword());
		}

		TEST_METHOD(TestParameterizedConstructor)
		{
			Login login("testUser", "testPass");
			Assert::AreEqual(std::string("testUser"), login.getUsername());
			Assert::AreEqual(std::string("testPass"), login.getPassword());
		}

		TEST_METHOD(TestSetUsername)
		{
			Login login;
			login.setUsername("newUser");
			Assert::AreEqual(std::string("newUser"), login.getUsername());
		}

		TEST_METHOD(TestSetPassword)
		{
			Login login;
			login.setPassword("newPass");
			Assert::AreEqual(std::string("newPass"), login.getPassword());
		}

		TEST_METHOD(TestAttemptLogin)
		{
			Login login("validUser", "validPass");
			Assert::IsTrue(login.attemptLogin());
		}
		TEST_METHOD(Constructor_ValidArguments)
		{
			// Arrange & Act
			PetAdopter adopter("John", "Doe", "johndoe", "securepassword");

			// Assert
			Assert::AreEqual(std::string("John"), adopter.getFirstName());
			Assert::AreEqual(std::string("Doe"), adopter.getLastName());
			Assert::AreEqual(std::string("johndoe"), adopter.getUsername());
			Assert::AreEqual(std::string("securepassword"), adopter.getPassword());
		}

		TEST_METHOD(SetAdopterFirstName_ValidName)
		{
			// Arrange
			PetAdopter adopter;
			std::string validFirstName = "Jane";

			// Act
			adopter.setFirstName(validFirstName);

			// Assert
			Assert::AreEqual(validFirstName, adopter.getFirstName());
		}

		TEST_METHOD(SetAdopterFirstName_InvalidName)
		{
			// Arrange
			PetAdopter adopter;
			auto func = [&] { adopter.setFirstName(""); };

			// Assert
			Assert::ExpectException<std::invalid_argument>(func);
		}
		TEST_METHOD(SetAdopterLastName_ValidName) {
			// Arrange
			PetAdopter adopter;
			std::string validLastName = "Smith";

			// Act
			adopter.setLastName(validLastName);

			// Assert
			Assert::AreEqual(validLastName, adopter.getLastName());
		}

		TEST_METHOD(SetAdopterLastName_InvalidName) {
			// Arrange
			PetAdopter adopter;
			auto func = [&] { adopter.setLastName(""); };

			// Assert
			Assert::ExpectException<std::invalid_argument>(func);
		}
		TEST_METHOD(SetAdopterUsername_Valid) {
			// Arrange
			PetAdopter adopter;
			std::string validUsername = "jane_doe";

			// Act
			adopter.setUsername(validUsername);

			// Assert
			Assert::AreEqual(validUsername, adopter.getUsername());
		}

		TEST_METHOD(SetAdopterUsername_Invalid) {
			// Arrange
			PetAdopter adopter;
			auto func = [&] { adopter.setUsername(""); };

			// Assert
			Assert::ExpectException<std::invalid_argument>(func);
		}
		TEST_METHOD(SetAdopterPassword_Valid) {
			// Arrange
			PetAdopter adopter;
			std::string validPassword = "VerySecure123!";

			// Act
			adopter.setPassword(validPassword);

			// Assert
			Assert::AreEqual(validPassword, adopter.getPassword());
		}

		TEST_METHOD(SetAdopterPassword_InvalidShort) {
			// Arrange
			PetAdopter adopter;
			auto func = [&] { adopter.setPassword("123"); };

			// Assert
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(SetAdopterPassword_InvalidLong) {
			// Arrange
			PetAdopter adopter;
			std::string invalidPassword(101, 'a');  // Too long

			// Act
			auto action = [&] { adopter.setPassword(invalidPassword); };

			// Assert
			Assert::ExpectException<std::invalid_argument>(action);
		}

		TEST_METHOD(SetFirstName_Invalid)
		{
			// Arrange
			PetSeller seller;
			std::string invalidFirstName = "";  // Empty string is invalid

			// Act & Assert
			auto action = [&seller, &invalidFirstName] { seller.setFirstName(invalidFirstName); };
			Assert::ExpectException<std::invalid_argument>(action);
		}

	

		TEST_METHOD(SetLastName_Invalid)
		{
			// Arrange
			PetSeller seller;
			std::string invalidLastName = std::string(51, 'a');  // Too long name

			// Act & Assert
			auto action = [&seller, &invalidLastName] { seller.setLastName(invalidLastName); };
			Assert::ExpectException<std::invalid_argument>(action);
		}

		TEST_METHOD(SetProvince_Valid)
		{
			// Arrange
			PetSeller seller;
			std::string validProvince = "ON";  // Valid province code

			// Act
			seller.setProvince(validProvince);

			// Assert
			Assert::AreEqual(validProvince, seller.getProvince());
		}

		TEST_METHOD(SetProvince_Invalid)
		{
			// Arrange
			PetSeller seller;
			std::string invalidProvince = "XX";  // Invalid province code

			// Act & Assert
			auto action = [&seller, &invalidProvince] { seller.setProvince(invalidProvince); };
			Assert::ExpectException<std::invalid_argument>(action);
		}
		TEST_METHOD(SetUsername_Valid) {
			// Arrange
			PetSeller seller;
			std::string validUsername = "john_doe";

			// Act
			seller.setUsername(validUsername);

			// Assert
			Assert::AreEqual(validUsername, seller.getUsername());
		}

		TEST_METHOD(SetUsername_Invalid) {
			// Arrange
			PetSeller seller;
			std::string invalidUsername = std::string(51, 'a');  // Username too long

			// Act & Assert
			auto action = [&seller, &invalidUsername] { seller.setUsername(invalidUsername); };
			Assert::ExpectException<std::invalid_argument>(action);
		}
		TEST_METHOD(SetPassword_Valid) {
			// Arrange
			PetSeller seller;
			std::string validPassword = "securePassword123";

			// Act
			seller.setPassword(validPassword);

			// Assert
			Assert::AreEqual(validPassword, seller.getPassword());
		}

		TEST_METHOD(SetPassword_InvalidShort) {
			// Arrange
			PetSeller seller;
			std::string invalidPassword = "123";  // Password too short

			// Act & Assert
			auto action = [&seller, &invalidPassword] { seller.setPassword(invalidPassword); };
			Assert::ExpectException<std::invalid_argument>(action);
		}
		TEST_METHOD(SetBusinessLocation_Valid) {
			// Arrange
			PetSeller seller;
			std::string validLocation = "123 Pet Street";

			// Act
			seller.setBusinessLocation(validLocation);

			// Assert
			Assert::AreEqual(validLocation, seller.getBusinessLocation());
		}

		TEST_METHOD(SetBusinessLocation_Invalid) {
			// Arrange
			PetSeller seller;
			std::string invalidLocation = std::string(101, 'a');  // Location string too long

			// Act & Assert
			auto action = [&seller, &invalidLocation] { seller.setBusinessLocation(invalidLocation); };
			Assert::ExpectException<std::invalid_argument>(action);
		}
		TEST_METHOD(SetPostalCode_Valid) {
			// Arrange
			PetSeller seller;
			std::string validPostalCode = "M5W 1E6";  // Valid Canadian postal code

			// Act
			seller.setPostalCode(validPostalCode);

			// Assert
			Assert::AreEqual(validPostalCode, seller.getPostalCode());
		}
		TEST_METHOD(SetPhoneNumber_Valid) {
			// Arrange
			PetSeller seller;
			std::string validPhoneNumber = "1234567890";  // Valid 10 digit number

			// Act
			seller.setPhoneNumber(validPhoneNumber);

			// Assert
			Assert::AreEqual(validPhoneNumber, seller.getPhoneNumber());
		}

		TEST_METHOD(SetPhoneNumber_InvalidLength) {
			// Arrange
			PetSeller seller;
			std::string invalidPhoneNumber = "123";  // Too short to be valid

			// Act & Assert
			auto action = [&seller, &invalidPhoneNumber] { seller.setPhoneNumber(invalidPhoneNumber); };
			Assert::ExpectException<std::invalid_argument>(action);
		}

		TEST_METHOD(SetPostalCode_InvalidFormat) {
			// Arrange
			PetSeller seller;
			std::string invalidPostalCode = "ABCDE12345";  // Invalid format

			// Act & Assert
			auto action = [&seller, &invalidPostalCode] { seller.setPostalCode(invalidPostalCode); };
			Assert::ExpectException<std::invalid_argument>(action);
		}
		TEST_METHOD(SetPassword_InvalidLong) {
			// Arrange
			PetSeller seller;
			std::string invalidPassword = std::string(101, 'a');  // Password too long

			// Act & Assert
			auto action = [&seller, &invalidPassword] { seller.setPassword(invalidPassword); };
			Assert::ExpectException<std::invalid_argument>(action);
		}

		TEST_METHOD(SetPassword_Boundary_ValidShort) {
			// Arrange
			PetSeller seller;
			std::string boundaryPassword = "123456";  // Exactly at the minimum valid length

			// Act
			seller.setPassword(boundaryPassword);

			// Assert
			Assert::AreEqual(boundaryPassword, seller.getPassword());
		}

		TEST_METHOD(SetPassword_Boundary_ValidLong) {
			// Arrange
			PetSeller seller;
			std::string boundaryPassword = std::string(100, 'a');  // Exactly at the maximum valid length

			// Act
			seller.setPassword(boundaryPassword);

			// Assert
			Assert::AreEqual(boundaryPassword, seller.getPassword());
		}

		TEST_METHOD(ProvinceEnum_ToString_AB)
		{
			// Arrange & Act
			std::string result = to_string(ProvinceEnum::AB);

			// Assert
			Assert::AreEqual(std::string("Alberta"), result);
		}

		TEST_METHOD(ProvinceEnum_ToString_BC)
		{
			// Arrange & Act
			std::string result = to_string(ProvinceEnum::BC);

			// Assert
			Assert::AreEqual(std::string("British Columbia"), result);
		}

		
		TEST_METHOD(ProvinceEnum_ToString_Unknown)
		{
			// Arrange
			// Cast an integer to ProvinceEnum to simulate an undefined enum value
			ProvinceEnum unknownProvince = static_cast<ProvinceEnum>(9999);

			// Act
			std::string result = to_string(unknownProvince);

			// Assert
			Assert::AreEqual(std::string("Unknown"), result);
		}
		TEST_METHOD(DefaultConstructor)
		{
			// Arrange & Act
			UserProfileViewer userProfile;

			// Assert
			Assert::IsFalse(userProfile.getIsSeller());
			Assert::AreEqual(std::string(""), userProfile.getBusinessLocation());
			// ... additional assertions for default constructor
		}

		TEST_METHOD(SetBusinessLocation_Valid_AsSeller)
		{
			// Arrange
			UserProfileViewer userProfile;
			userProfile.setIsSeller(true); // Set the user as a seller

			// Act
			userProfile.setBusinessLocation("123 Pet Street");

			// Assert
			Assert::AreEqual(std::string("123 Pet Street"), userProfile.getBusinessLocation());
		}

		TEST_METHOD(SetBusinessLocation_Invalid_AsSeller)
		{
			// Arrange
			UserProfileViewer userProfile;
			userProfile.setIsSeller(true); // Set the user as a seller

			// Act & Assert
			auto func = [&] { userProfile.setBusinessLocation(""); };
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(SetBusinessLocation_Valid_AsBuyer)
		{
			// Arrange
			UserProfileViewer userProfile;
			userProfile.setIsSeller(false); // Set the user as a buyer

			// Act
			userProfile.setBusinessLocation("123 Pet Street"); // Buyers are not required to have a business location

			// Assert
			Assert::AreEqual(std::string("123 Pet Street"), userProfile.getBusinessLocation());
		}

		TEST_METHOD(SetProvince_Valid_AsSeller)
		{
			// Arrange
			UserProfileViewer userProfile;
			userProfile.setIsSeller(true); // Set the user as a seller

			// Act
			userProfile.setProvince("ON");

			// Assert
			Assert::AreEqual(std::string("ON"), userProfile.getProvince());
		}

		TEST_METHOD(SetProvince_Invalid_AsSeller)
		{
			// Arrange
			UserProfileViewer userProfile;
			userProfile.setIsSeller(true); // Set the user as a seller

			// Act & Assert
			auto func = [&] { userProfile.setProvince(""); };
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(SetPreferences_AnyUser)
		{
			// Arrange
			UserProfileViewer userProfile;

			// Act
			userProfile.setPreferences("Cats"); // Both buyers and sellers can set preferences

			// Assert
			Assert::AreEqual(std::string("Cats"), userProfile.getPreferences());
		}
		TEST_METHOD(SetUserProfileUsername_Empty) {
			// Arrange
			UserProfileViewer userProfile;

			// Act
			userProfile.setUsername("");

			// Assert
			Assert::AreEqual(std::string(""), userProfile.getUsername());
		}

		TEST_METHOD(SetUserProfileFirstName_Empty) {
			// Arrange
			UserProfileViewer userProfile;

			// Act
			userProfile.setFirstName("");

			// Assert
			Assert::AreEqual(std::string(""), userProfile.getFirstName());
		}

		TEST_METHOD(SetUserProfileLastName_Empty) {
			// Arrange
			UserProfileViewer userProfile;

			// Act
			userProfile.setLastName("");

			// Assert
			Assert::AreEqual(std::string(""), userProfile.getLastName());
		}

		

			TEST_METHOD(TestPacketDefaultConstructor)
			{
				Packet packet;
				// Assuming you have getters or public members to verify the default state
				// Adjust the assertions based on the actual default values
				Assert::AreEqual(0, (int)packet.pktHeader.reqType, L"Request type should be initialized to 0/UNKNOWN");
				// Add more assertions as necessary to cover all initial states
			}
			TEST_METHOD(TestLoginConstructor)
			{
				std::string username = "testUser";
				std::string password = "hashedPassword";
				Packet packet(username, password);

				// Verify the login information is correctly set
				Assert::AreEqual(username + '\0', packet.loginInfo.username, L"Username mismatch");
				Assert::AreEqual(password + '\0', packet.loginInfo.hashedPassword, L"Password mismatch");

				// Verify header is set correctly
				Assert::IsTrue(packet.pktHeader.reqType == LOGIN_ACT, L"Request type should be LOGIN_ACT");
				// Continue with more assertions as needed to fully test the constructor
			}
			
			TEST_METHOD(LogUpConstructorTest)
			{
				// Arrange
				std::string firstName = "John";
				std::string lastName = "Doe";
				std::string username = "johndoe";
				std::string hashedPassword = "hashedpass";
				std::string businessAddress = "1234 Business St.";
				std::string province = "Business Province";
				std::string postalCode = "123456";
				unsigned long int businessPhone = 1234567890;
				unsigned int licenseNumber = 123456;
				unsigned int animalType = 1; // Assuming 1 represents a specific animal type
				bool vaccinationStatus = true;
				unsigned int age = 5;

				Packet packet(firstName, lastName, username, hashedPassword, businessAddress, province, postalCode,
					businessPhone, licenseNumber, animalType, vaccinationStatus, age);

				
				Assert::AreEqual(firstName, packet.lUOwners.firstName, L"First name mismatch.");
				Assert::AreEqual(lastName, packet.lUOwners.lastName, L"Last name mismatch.");
				

				// Verify header fields
				Assert::IsTrue(packet.pktHeader.reqType == LOGUP, L"Request type should be LOGUP.");
				
			}




	};
}
