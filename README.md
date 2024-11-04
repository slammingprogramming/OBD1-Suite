# Universal OBD-I Debugging Suite

The Universal OBD-I Debugging Suite is a comprehensive, cross-platform diagnostic tool tailored for automotive enthusiasts, mechanics, and technicians to troubleshoot and diagnose vehicles equipped with OBD-I (On-Board Diagnostics, version I) systems. Supporting various OBD-I protocols, such as the ALDL protocol commonly used by General Motors, this suite offers an extensive range of features to assist in identifying issues across diverse vehicle makes and models.

## Key Features

- **Wide OBD-I Protocol Support:** Seamlessly interact with multiple OBD-I protocols to retrieve diagnostic data across various vehicle systems.
  
- **Customizable Communication Interface:** Connect your computer to the vehicle’s OBD-I port via a spliced cable or adapter. Supports a configurable baud rate and data bit settings to ensure compatibility with unique OBD-I system requirements.

- **Data Collection & System Coverage:** Access and interpret diagnostic data from a variety of systems, including:
  - **Engine** (RPM, temperature, throttle position)
  - **Transmission** (gear ratio, shift points)
  - **ABS** (Anti-lock Braking System error codes and status)
  - **SIR** (Supplemental Inflatable Restraint diagnostics)
  - **Electrical Systems** (battery voltage, alternator output, and other electrical faults)
  
- **Detailed DTC (Diagnostic Trouble Codes) Interpretation:** Decode generic and manufacturer-specific trouble codes, along with recommended actions or potential causes for each error.

- **Real-time Data Monitoring:** Continuously track live data such as RPM, coolant temperature, throttle position, and vehicle speed. Use real-time data to verify repairs or monitor performance changes.

- **Data Logging and Exporting:** Save diagnostic session logs in formats like CSV or JSON to review, analyze, or share diagnostics data after completing an inspection.

- **Enhanced User Interface:** Intuitive interface with customizable themes, filterable data views, and collapsible sections for ease of use. Ideal for technicians and hobbyists alike.

- **Modular Architecture and Extensibility:** Designed for future updates, allowing new protocols or features to be integrated as automotive technology evolves.

- **Report Generation and Printing:** Create detailed diagnostic reports that summarize key data, DTCs, system status, and real-time observations. Reports can be saved, printed, or shared as needed.

## Planned Additional Features

- **Advanced Data Visualization:** Implement data graphs, real-time charts, and trend analysis to provide insights into vehicle performance over time.
  
- **Protocol Analyzer:** In-depth analysis tools for decoding raw data streams for protocols not fully supported, enabling easier expansion to non-standard OBD-I systems.
  
- **Customizable Alerts and Notifications:** Set thresholds for specific sensor data (e.g., engine temperature) and receive alerts if readings exceed safe limits.

- **Community-Driven Plugin Support:** Allow users to create and install plugins for specific makes, models, or proprietary protocols, enhancing the versatility of the suite.

## Getting Started

To get started with the Universal OBD-I Debugging Suite:

1. **Install Dependencies**: Follow the setup instructions for dependencies and compatible OBD-I adapters.
2. **Connect Hardware**: Plug a spliced cable or adapter into the vehicle’s OBD-I port and ensure proper connections to avoid data inconsistencies.
3. **Run Program**: Launch the suite and configure the communication interface.
4. **Select Data Stream**: Choose the diagnostic data category or live data feed to access.
5. **Analyze Data**: Use tools like error code interpretation, live data monitoring, and report generation to diagnose and troubleshoot vehicle issues.
6. **Save or Export Data**: Export session logs and reports for future reference or sharing with other technicians.

## Requirements

- Operating System: Windows, macOS, or Linux
- Hardware: Spliced cable or compatible adapter for OBD-I port connection
- Software: [Dependency Requirements] (docs/INSTALL.md)

## Issues & Contributions

To report a bug or suggest an enhancement, visit our [GitHub Issues page](https://github.com/slammingprogramming/OBD1-Suite/issues). Pull requests for improvements and new features are welcome!

## License

We would like to express our gratitude to the open-source community for their invaluable contributions. This program utilizes various libraries and resources, which are credited in the [Acknowledgements](ACKNOWLEDGEMENTS.md) file.

## Acknowledgements

Special thanks to the open-source community for their support. See [Acknowledgements.md](ACKNOWLEDGEMENTS.md) for details.

## Disclaimer

This tool is intended for diagnostic and debugging purposes only by individuals familiar with OBD-I systems. Use with caution, and consult professional advice when interpreting results. The creators assume no liability for damages arising from use and this software is offered with no warranty or guarantee.
