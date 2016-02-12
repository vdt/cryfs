#include "testutils/CliTest.h"

using cpputils::TempFile;

//Tests that cryfs is correctly setup according to the CLI parameters specified
using CliTest_Setup = CliTest;

TEST_F(CliTest_Setup, NoSpecialOptions) {
    //Specify --cipher and --extpass parameters to make it non-interactive
    //TODO Remove "-f" parameter, once EXPECT_RUN_SUCCESS can handle that
    EXPECT_RUN_SUCCESS({basedir.c_str(), mountdir.c_str(), "--cipher", "aes-256-gcm", "--extpass", "echo mypassword", "-f"}, mountdir);
}

TEST_F(CliTest_Setup, NotexistingLogfileGiven) {
    TempFile notexisting_logfile(false);
    //Specify --cipher and --extpass parameters to make it non-interactive
    //TODO Remove "-f" parameter, once EXPECT_RUN_SUCCESS can handle that
    EXPECT_RUN_SUCCESS({basedir.c_str(), mountdir.c_str(), "-f", "--cipher", "aes-256-gcm", "--extpass", "echo mypassword", "--logfile", notexisting_logfile.path().c_str()}, mountdir);
    //TODO Expect logfile is used (check logfile content)
}

TEST_F(CliTest_Setup, ExistingLogfileGiven) {
    //Specify --cipher and --extpass parameters to make it non-interactive
    //TODO Remove "-f" parameter, once EXPECT_RUN_SUCCESS can handle that
    EXPECT_RUN_SUCCESS({basedir.c_str(), mountdir.c_str(), "-f", "--cipher", "aes-256-gcm", "--extpass", "echo mypassword", "--logfile", logfile.path().c_str()}, mountdir);
    //TODO Expect logfile is used (check logfile content)
}

TEST_F(CliTest_Setup, ConfigfileGiven) {
    //Specify --cipher and --extpass parameters to make it non-interactive
    //TODO Remove "-f" parameter, once EXPECT_RUN_SUCCESS can handle that
    EXPECT_RUN_SUCCESS({basedir.c_str(), mountdir.c_str(), "-f", "--cipher", "aes-256-gcm", "--extpass", "echo mypassword", "--config", configfile.path().c_str()}, mountdir);
}

TEST_F(CliTest_Setup, FuseOptionGiven) {
    //Specify --cipher and --extpass parameters to make it non-interactive
    //TODO Remove "-f" parameter, once EXPECT_RUN_SUCCESS can handle that
    EXPECT_RUN_SUCCESS({basedir.c_str(), mountdir.c_str(), "-f", "--cipher", "aes-256-gcm", "--extpass", "echo mypassword", "--", "-f"}, mountdir);
}