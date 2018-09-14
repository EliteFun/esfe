// TODO: rename to ConfigManager.hpp
// csv support?
// loads *.config files

/* *.config SYNTAX:
variable=value
# comment, it's easy!
*/

// *.dat : binary
// *.cfg : normal
// Add signature at begining of config files:
// .fileName.extension

// for now, configs, must be hand-made

class ConfigLoader
{
    public:
        /** Default constructor */
        ConfigLoader( bool isBinary );
        /** Default destructor */
        virtual ~ConfigLoader();

    protected:

    private:
};

class ConfigWriter
{
    
};
