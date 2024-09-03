#pragma once

#ifdef KNOTH_PLATFORM_WINDOWS
extern Knoth::Application* Knoth::CreateApplication();

int main(int argc, char** arcv) {
	auto app = Knoth::CreateApplication();
	Knoth::Log* log = new Knoth::Log("TestLog");
	log->Print("Entry point print", __FILE__, __LINE__);
	LOG("Entry point print");
	LOG_TEST("{0} {1} random numbers", "asdfasdf", 32);
	//PRINT_LOG(e.ToString());
	PRINT_INFO("Info");
	PRINT_ERROR("Error");
	app->Run();
	delete app;
}
#else
	#error Only support Windows
#endif